#pragma once
#include "stdlib.h"

enum instruction
{
    //op load
    //E
    LB=0,
    LH,
    LW,
    LBU,
    LHU=4,
    //op immdediate 
    ADDI=5,
    SLLI,
    SLTI,
    SLTIU,
    XORI,
    SRAI,
    SRLI,
    ORI,
    ANDI=13,
    //auipc
    AUIPC,
    //store
    SB,
    SH,
    SW,
    //op 
    ADD,
    SLL,
    SLT=20,
    SLTU,
    XOR,
    SRL,
    OR,
    AND,
    MUL,
    MULH,
    MULHSU,
    MULHU,
    DIV=30,
    DIVU,
    REM,
    REMU,
    SUB,
    SRA,
    //op lui
    LUI,
    //op Branch
    BEQ,
    BNE,
    BLT,
    BGE,
    BLTU,
    BGEU,
    //op Jal
    JALR,
    JAL=45,
    //system
    ECALL,
    EBREAK=47,
};

void instruction_count(int instruction);
void instruction_count_initialize();
void top10_instruction();
void stats_information();
void CPU_cycles();
void jump_forward_count();
void jump_backward_count();
void cycle_count();
void branch_count();
void jump_count(const int32_t imm);
void jalr_jump_count(const int32_t before,const int32_t after);





