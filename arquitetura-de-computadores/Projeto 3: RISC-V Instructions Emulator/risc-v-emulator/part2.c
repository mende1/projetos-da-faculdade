#include <stdio.h> /* for stderr */
#include <stdlib.h> /* for exit() */
#include "types.h"
#include "utils.h"
#include "riscv.h"

void execute_rtype(Instruction, Processor *);
void execute_itype_except_load(Instruction, Processor *);
void execute_branch(Instruction, Processor *);
void execute_jal(Instruction, Processor *);
void execute_load(Instruction, Processor *, Byte *);
void execute_store(Instruction, Processor *, Byte *);
void execute_ecall(Processor *, Byte *);
void execute_lui(Instruction, Processor *);

void execute_instruction(Instruction instruction,Processor *processor,Byte *memory) {    
    /* YOUR CODE HERE: COMPLETE THE SWITCH STATEMENTS */
    switch(0) { /* What do we switch on? */
        /* YOUR CODE HERE */
        default: /* undefined opcode */
            handle_invalid_instruction(instruction);
            exit(-1);
            break;
    }
}

void execute_rtype(Instruction instruction, Processor *processor) {
    switch(0) { /* What do we switch on? */
        /* YOUR CODE HERE */
        default:
            handle_invalid_instruction(instruction);
            exit(-1);
            break;
    }
}

void execute_itype_except_load(Instruction instruction, Processor *processor) {
    int shiftOp;
    shiftOp = -1;
    switch(0) { /* What do we switch on? */
        /* YOUR CODE HERE */
        default:
            handle_invalid_instruction(instruction);
            break;
    }
}

void execute_ecall(Processor *p, Byte *memory) {
    switch(0) { /* What do we switch on? */
        /* YOUR CODE HERE */
        default: /* undefined ecall */
            printf("Illegal ecall number %d\n", -1); /* What stores the ecall arg? */
            exit(-1);
            break;
    }
}

void execute_branch(Instruction instruction, Processor *processor) {
    int branchaddr;
    branchaddr = 0;
    /* Remember that the immediate portion of branches
       is counting half-words, so make sure to account for that. */
    switch(0) { /* What do we switch on? */
        /* YOUR CODE HERE */
        default:
            handle_invalid_instruction(instruction);
            exit(-1);
            break;
    }
}

void execute_load(Instruction instruction, Processor *processor, Byte *memory) {
    switch(0) { /* What do we switch on? */
        /* YOUR CODE HERE */
        default:
            handle_invalid_instruction(instruction);
            break;
    }
}

void execute_store(Instruction instruction, Processor *processor, Byte *memory) {
    switch(0) { /* What do we switch on? */
        /* YOUR CODE HERE */
        default:
            handle_invalid_instruction(instruction);
            exit(-1);
            break;
    }
}

void execute_jal(Instruction instruction, Processor *processor) {
    int nextPC;
    nextPC = 0;
    /* YOUR CODE HERE */
}

void execute_lui(Instruction instruction, Processor *processor) {
    int imm;
    imm = 0;
    /* YOUR CODE HERE */  
}

/* Checks that the address is aligned correctly */
int check(Address address,Alignment alignment) {
    if(address>0 && address < MEMORY_SPACE){
        if(alignment == LENGTH_BYTE){
            return 1;
        }
        else if( alignment == LENGTH_HALF_WORD ){
            return address%2 == 0;
        }
        else if (alignment == LENGTH_WORD){
            return address%4 ==0;
        }
    }
    
    return 0;
    
}

void store(Byte *memory,Address address,Alignment alignment,Word value, int check_align) {
    if((check_align && !check(address,alignment)) || (address >= MEMORY_SPACE)) {
        handle_invalid_write(address);
    }
    /* YOUR CODE HERE */
}

Word load(Byte *memory,Address address,Alignment alignment, int check_align) {
    if((check_align && !check(address,alignment)) || (address >= MEMORY_SPACE)) {
    handle_invalid_read(address);
    }
    
    /* YOUR CODE HERE */
    uint32_t data = 0; // initialize our return value to zero
    return data;
}


