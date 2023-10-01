#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACK_INIT_SIZE 20
#define MAXBUFFER 10

typedef enum { ERROR, OK }Status;
typedef char ElemType;
typedef double ElemTypef;
typedef struct
{
    ElemType* pBase;
    ElemType* pTop;
    int stackSize;
}Stack;
typedef struct
{
    ElemTypef* pBasef;
    ElemTypef* pTopf;
    int stackSizef;
}Stackf;

void InitStack(Stack* s);
void stack_free(Stack* s);
void stack_clear(Stack* s);
Status Push(Stack* s, ElemType e);
Status Pop(Stack* s, ElemType* e);
int StackLen(Stack s);
Status Stack_Get_pTop(Stack s, ElemType* e);
Status stack_traverse(Stack* s, Status(*visit)());
void InitStackf(Stackf* s);
void stack_freef(Stackf* s);
void stack_clearf(Stackf* s);
Status Pushf(Stackf* s, ElemTypef e);
Status Popf(Stackf* s, ElemTypef* e);
int StackLenf(Stackf s);
Status Stack_Get_pTopf(Stackf s, ElemTypef* e);
Status stack_traversef(Stackf* s, Status(*visit)());