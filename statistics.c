#include "statistics.h"
#include "stdio.h"
#include "stdlib.h"

#define TOTAL_INSTRUCTION 48

struct Instruction{
    const char* name;
    int count;
};
static unsigned long cycles=0;
static unsigned long branch=0;
static unsigned long jump_forward=0;
static unsigned long jump_backward=0;

struct Instruction frequency[TOTAL_INSTRUCTION]=
{
    {"LB",0},
    {"LH",0},
    {"LW",0},
    {"LBU",0},
    {"LHU",0},
    {"ADDI",0},
    {"SLLI",0},
    {"SLTI",0},
    {"SLTIU",0},
    {"XORI",0},
    {"SRRI",0},
    {"SRLI",0},
    {"ORI",0},
    {"ANDI",0},
    {"AUIPC",0},
    {"SB",0},
    {"SH",0},
    {"SW",0},
    {"ADD",0},
    {"SLL",0},
    {"SLT",0},
    {"SLTU",0},
    {"XOR",0},
    {"SRL",0},
    {"OR",0},
    {"AND",0},
    {"MUL",0},
    {"MULH",0},
    {"MULHSU",0},
    {"MULHU",0},
    {"DIV",0},
    {"DIVU",0},
    {"REM",0},
    {"REMU",0},
    {"SUB",0},
    {"SRA",0},
    {"LUI",0},
    {"BEQ",0},
    {"BNE",0},
    {"BLT",0},
    {"BGE",0},
    {"BLTU",0},
    {"BGEU",0},
    {"JALR",0},
    {"JAL",0},
    {"ECALL",0},
    {"EBREAK",0}
};

void instruction_count(int instruction)
{
    if(instruction<TOTAL_INSTRUCTION)
        frequency[instruction].count++;
}
void instruction_count_initialize()
{
    for(int i=0;i<TOTAL_INSTRUCTION;i++)
        frequency[i].count=0;
}

void branch_count()
{
    branch++;
}
void cycle_count()
{
    cycles++;
}

void jump_count(const int32_t imm)
{
   imm>0 ? jump_forward_count():jump_backward_count();
}
void jalr_jump_count(const int32_t before,const int32_t after)
{
    jump_count(after-before);
}

void jump_forward_count()
{
    jump_forward++;
}
void jump_backward_count()
{
    jump_backward++;
}

void CPU_cycles()
{
    printf("\nTotal CPU cycles:%lu\n",cycles);
}

void top10_instruction()
{
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<TOTAL_INSTRUCTION;j++)
        {
            if(frequency[i].count<frequency[j].count)
            {
                struct Instruction temp;
                temp=frequency[i];
                frequency[i]=frequency[j];
                frequency[j]=temp;
            }
        }
    }
    unsigned long total=0;
    for(int i=0;i<TOTAL_INSTRUCTION;i++)
        total+=frequency[i].count;

    printf("===============top 10 frequency========================:\n");
    for(int i=0;i<10;i++)
        printf("\t %s:\t\t %d (%.2f %%)\n",frequency[i].name,frequency[i].count,frequency[i].count*100.f/total);
}

void stats_information()
{
    CPU_cycles();
    unsigned long total=jump_forward+jump_backward;
    printf("jump forward counter:%lu  (%.2f %%)\n",jump_forward,jump_forward*100.0f/total);
    printf("jump backward counter:%lu (%.2f %%)\n",jump_backward,jump_backward*100.0f/total);
    top10_instruction();
}

