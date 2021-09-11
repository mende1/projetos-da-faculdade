#include "riscv.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>

/* WARNING: DO NOT CHANGE THIS FILE.
 YOU PROBABLY DON'T EVEN NEED TO LOOK AT IT... */

/* Pointer to simulator memory */
Byte *memory;

void execute(Processor *processor,int prompt,int print) {
    Instruction instruction;
    
    /* fetch an instruction */
    instruction.bits = load(memory,processor->PC,LENGTH_WORD, 1);

    /* interactive-mode prompt */
    if(prompt) {
        if(prompt==1) {
            printf("simulator paused,enter to continue...");
            while(getchar()!='\n');
        }
        printf("%08x: ",processor->PC);
        decode_instruction(instruction);
    }
    
    execute_instruction(instruction,processor,memory);
    
    /* enforce $0 being hard-wired to 0 */
    processor->R[0] = 0;
    
    /* print trace */
    if(print) {
        int i,j;
        for(i=0;i<8;i++) {
            for(j=0;j<4;j++) {
                printf("r%2d=%08x ",i*4+j,processor->R[i*4+j]);
            }
            puts("");
        }
	printf("\n");
    }
}

void load_program(uint8_t *mem, size_t memsize UNUSED, int startaddr, const char *filename, int disasm) {
    FILE *file = fopen(filename, "r");
    const int MAX_SIZE = 50;
    char line[MAX_SIZE];
    int instruction, offset = 0;    

    while (fgets(line, MAX_SIZE, file) != NULL) {
        instruction = (int32_t) strtol(line, NULL, 16);
        mem[startaddr + offset] = instruction & 0xFF;
	mem[startaddr + offset + 1] = (instruction >> 8) & 0xFF;
	mem[startaddr + offset + 2] = (instruction >> 16) & 0xFF;
	mem[startaddr + offset + 3] = (instruction >> 24) & 0xFF;
        if (disasm) {
	    uint8_t *inst_ptr = (uint8_t *) &instruction;
	    printf("%08x: ", startaddr + offset);
            decode_instruction(*((Instruction *) inst_ptr));
	}
        offset += 4;
    } 
}

int main(int argc,char** argv) {
    /* options */
    int opt_disasm = 0,opt_regdump = 0,opt_interactive = 0, i;
    
    /* the architectural state of the CPU */
    Processor processor;
    
    /* parse the command-line args */
    int c;
    while((c=getopt(argc,argv,"drit"))!=-1) {
        switch (c) {
            case 'd':
                opt_disasm = 1;
                break;
            case 'r':
                opt_regdump = 1;
                break;
            case 'i':
                opt_interactive = 1;
                break;
            case 't':
                opt_interactive = 2;
                break;
            default:
                fprintf(stderr,"Bad option %c\n",c);
                return -1;
        }
    }
    
    /* make sure we got an executable filename on the command line */
    if(argc<=optind) {
        fprintf(stderr,"Give me an executable file to run!\n");
        return -1;
    }
    
    
    
    /* load the executable into memory */
    assert(memory == NULL);
    memory = calloc(MEMORY_SPACE,sizeof(uint8_t)); // allocate zeroed memory
    assert(memory != NULL);
  
    /* SEt the PC to 0x1000 */ 
    processor.PC = 0x1000;
    load_program(memory, MEMORY_SPACE, processor.PC, argv[optind], opt_disasm);
    
    /* if we're just disassembling,exit here */
    if(opt_disasm) {
        return 0;
    }
    
    /* initialize the CPU */
    /* zero out all registers */
    for(i=0;i<32;i++) {
        processor.R[i] = 0;
    }
   
    /* Set the global pointer to 0x3000. We arbitrarily call this the middle of the static data segment */
    processor.R[3] = 0x3000;

    /* Set the stack pointer near the top of the memory array */
    processor.R[2] = 0xEFFFF;
 
    /* simulate forever! */
    for(;;) {
        execute(&processor,opt_interactive,opt_regdump);
    }
    
    return 0;
}
