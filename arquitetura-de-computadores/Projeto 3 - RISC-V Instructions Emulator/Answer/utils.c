#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

//sign extends a bitfield with given size
/* You may find implementing this function helpful */
int bitSigner( unsigned int field, unsigned int n){
    unsigned int n_field_bits = field & ((1U << n) - 1);

    // 1 -> negative; 0 -> positive
    unsigned int msb = field & (1U << (n - 1));

    unsigned int mask = msb ? ((1UL << 32) - 1) : 0;

    mask <<= n;

    mask ^= n_field_bits;

    return mask;
}

/* Remember that the offsets should return the offset in BYTES */

int get_branch_offset(Instruction instruction) {
    int offset = 0x00000000;

    offset |= instruction.sbtype.imm5 & 0x0000001e; // imm[1:4]

    offset |= (instruction.sbtype.imm7 << 5) & 0x000007e0; // imm[5:10]

    offset |= (instruction.sbtype.imm5 << 11) & 0x00000800; // imm[11]

    offset |= (instruction.sbtype.imm7 << 6) & 0x00001000; // imm[12]

    return bitSigner(offset, 13);
}

int get_jump_offset(Instruction instruction) {
    int offset = 0x00000000;

    offset |= (instruction.ujtype.imm >> 8) & 0x000007fe; // imm[1:10]

    offset |= (instruction.ujtype.imm << 3) & 0x00000800; // imm[11]

    offset |= (instruction.ujtype.imm << 12) & 0x000ff000; // imm[12:19]

    offset |= (instruction.ujtype.imm << 2) & 0x00100000;// imm[20]

    return bitSigner(offset, 21);
}

int get_store_offset(Instruction instruction) {
    int offset = 0x00000000;

    offset |= instruction.stype.imm5 & 0x0000001f; // imm[0:4]

    offset |= (instruction.stype.imm7 << 5) & 0x00000fe0; // imm[5:11]

    return bitSigner(offset, 12);
}

void handle_invalid_instruction(Instruction instruction) {
    printf("Invalid Instruction: 0x%08x\n", instruction.bits); 
}

void handle_invalid_read(Address address) {
    printf("Bad Read. Address: 0x%08x\n", address);
    exit(-1);
}

void handle_invalid_write(Address address) {
    printf("Bad Write. Address: 0x%08x\n", address);
    exit(-1);
}