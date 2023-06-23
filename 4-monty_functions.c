#include "monty.h"

void montyRotl(stack_t **stack, unsigned int lineNum);
void montyRotr(stack_t **stack, unsigned int lineNum);
void montyStack(stack_t **stack, unsigned int lineNum);
void montyQueue(stack_t **stack, unsigned int lineNum);

/**
 * montyRotl - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: The top value of the stack is moved to the bottom,
 *              shifting all other values up.
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
 * montyRotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: The bottom value of the stack is moved to the top,
 *              shifting all other values down.
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
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: Changes the mode of the data structure to stack,
 *              enabling stack-specific behavior.
 */
void montyStack(stack_t **stack, unsigned int lineNum)
{
    (*stack)->n = STACK;
    (void)lineNum;
}

/**
 * montyQueue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: Changes the mode of the data structure to queue,
 *              enabling queue-specific behavior.
 */
void montyQueue(stack_t **stack, unsigned int lineNum)
{
    (*stack)->n = QUEUE;
    (void)lineNum;
}
