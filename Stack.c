#include"Stack.h"
void InitStack(Stack* s)
{
    s->pBase = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!s->pBase) exit(0);
    s->pTop = s->pBase;
    s->stackSize = STACK_INIT_SIZE;

}

void stack_free(Stack* s)
{
    for (s->pBase; s->pBase < s->pTop; s->pBase++)
    {
        free(s->pBase);
    }
}

void stack_clear(Stack* s)
{
    s->pTop = s->pBase;
}

Status Push(Stack* s, ElemType e)
{

    if (s->pTop - s->pBase >= s->stackSize) return ERROR;
    *(s->pTop) = e;
    s->pTop++;
    return OK;
}

Status Pop(Stack* s, ElemType* e)
{
    if (s->pTop == s->pBase) return ERROR;

    *e = *--(s->pTop);
    return OK;
}

int StackLen(Stack s)
{
    return (s.pTop - s.pBase);
}

Status Stack_Get_pTop(Stack s, ElemType* e)
{
    if (s.pTop == s.pBase) return ERROR;
    *e = *(s.pTop); return OK;

}

Status stack_traverse(Stack* s, Status(*visit)())
{
    for (s->pBase; s->pBase < s->pTop; s->pBase++)
    {
        (*visit)(*(s->pBase));
    }
    return OK;

}

void InitStackf(Stackf* s)
{
    s->pBasef = (ElemTypef*)malloc(STACK_INIT_SIZE * sizeof(ElemTypef));
    if (!s->pBasef) exit(0);
    s->pTopf = s->pBasef;
    s->stackSizef = STACK_INIT_SIZE;

}

void stack_freef(Stackf* s)
{
    for (s->pBasef; s->pBasef < s->pTopf; s->pBasef++)
    {
        free(s->pBasef);
    }
}

void stack_clearf(Stackf* s)
{
    s->pTopf = s->pBasef;
}

Status Pushf(Stackf* s, ElemTypef e)
{

    if (s->pTopf - s->pBasef >= s->stackSizef) return ERROR;
    *(s->pTopf) = e;
    s->pTopf++;
    return OK;
}

Status Popf(Stackf* s, ElemTypef* e)
{
    if (s->pTopf == s->pBasef) return ERROR;

    *e = *--(s->pTopf);
    return OK;
}

int StackLenf(Stackf s)
{
    return (s.pTopf - s.pBasef);
}

Status Stack_Get_pTopf(Stackf s, ElemTypef* e)
{
    if (s.pTopf == s.pBasef) return ERROR;
    *e = *(s.pTopf); return OK;

}

Status stack_traversef(Stackf* s, Status(*visit)())
{
    for (s->pBasef; s->pBasef < s->pTopf; s->pBasef++)
    {
        (*visit)(*(s->pBasef));
    }
    return OK;

}
