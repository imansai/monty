#include "monty.h"


void montyRotl(stack_t **stack, unsigned int lineNum);
void montyRotr(stack_t **stack, unsigned int lineNum);
void montyStack(stack_t **stack, unsigned int lineNum);
void montyQueue(stack_t **stack, unsigned int lineNum);


/**
 * montyRotl - Rotates the top value of alinked list to the bottom.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void montyRotl(stack_t **stack, unsigned int lineNum)
{
    stack_t *top, *bottom;


    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;


    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;


    top->next->prev = *stack;
    (*stack)->next = top->next;
    bottom->next = top;
    top->next = NULL;
    top->prev = bottom;


    (void)lineNum;
}


/**
 * montyRotr - Rotates the bottom value of alinked list to the top.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void montyRotr(stack_t **stack, unsigned int lineNum)
{
    stack_t *top, *bottom;


    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;


    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;


    bottom->prev->next = NULL;
    (*stack)->next = bottom;
    bottom->prev = *stack;
    bottom->next = top;
    top->prev = bottom;


    (void)lineNum;
}


/**
 * montyStack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void montyStack(stack_t **stack, unsigned int lineNum)
{
    (*stack)->n = STACK;
    (void)lineNum;
}


/**
 * montyQueue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void montyQueue(stack_t **stack, unsigned int lineNum)
{
    (*stack)->n = QUEUE;
    (void)lineNum;
}
