#include "monty.h"


void montyPush(stack_t **stack, unsigned int lineNum);
void montyPall(stack_t **stack, unsigned int lineNum);
void montyPint(stack_t **stack, unsigned int lineNum);
void montyPop(stack_t **stack, unsigned int lineNum);
void montySwap(stack_t **stack, unsigned int lineNum);


/**
 * montyPush - Pushes value to alinked list.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void montyPush(stack_t **stack, unsigned int lineNum)
{
    stack_t *tmp, *new;
    int i;


    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        setErrorToken(handleErrorMalloc());
        return;
    }


    if (op_toks[1] == NULL)
    {
        setErrorToken(handleErrorNoInt(lineNum));
        return;
    }


    for (i = 0; op_toks[1][i]; i++)
    {
        if (op_toks[1][i] == '-' && i == 0)
            continue;
        if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
        {
            setErrorToken(handleErrorNoInt(lineNum));
            return;
        }
    }
    new->n = atoi(op_toks[1]);


    if (checkMode(*stack) == STACK)
    {
        tmp = (*stack)->next;
        new->prev = *stack;
        new->next = tmp;
        if (tmp)
            tmp->prev = new;
        (*stack)->next = new;
    }
    else
    {
        tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        new->prev = tmp;
        new->next = NULL;
        tmp->next = new;
    }
}


/**
 * montyPall - Prints the values of a linked list.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void montyPall(stack_t **stack, unsigned int lineNum)
{
    stack_t *tmp = (*stack)->next;


    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
    (void)lineNum;
}


/**
 * montyPint - Prints the top value of alinked list.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void montyPint(stack_t **stack, unsigned int lineNum)
{
    if ((*stack)->next == NULL)
    {
        setErrorToken(handleErrorPint(lineNum));
        return;
    }


    printf("%d\n", (*stack)->next->n);
}




/**
 * montyPop - Removes the top value element of alinked list.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void montyPop(stack_t **stack, unsigned int lineNum)
{
    stack_t *next = NULL;


    if ((*stack)->next == NULL)
    {
        setErrorToken(handleErrorPop(lineNum));
        return;
    }


    next = (*stack)->next->next;
    free((*stack)->next);
    if (next)
        next->prev = *stack;
    (*stack)->next = next;
}


/**
 * montySwap - Swaps the top two value elements of alinked list.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void montySwap(stack_t **stack, unsigned int lineNum)
{
    stack_t *tmp;


    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        setErrorToken(handleErrorShortStack(lineNum, "swap"));
        return;
    }


    tmp = (*stack)->next->next;
    (*stack)->next->next = tmp->next;
    (*stack)->next->prev = tmp;
    if (tmp->next)
        tmp->next->prev = (*stack)->next;
    tmp->next = (*stack)->next;
    tmp->prev = *stack;
    (*stack)->next = tmp;
}
