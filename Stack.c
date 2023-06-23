#include "monty.h"
#include <string.h>


void freeStack(stack_t **stack);
int initializeStack(stack_t **stack);
int checkMode(stack_t *stack);


/**
 * freeStack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void freeStack(stack_t **stack)
{
    stack_t *tmp = *stack;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}


/**
 * initializeStack - Initializes a stack_t stack with beginning
 *                   stack and ending queue nodes.
 * @stack: A pointer to an uninitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int initializeStack(stack_t **stack)
{
    stack_t *s;

    s = malloc(sizeof(stack_t));
    if (s == NULL)
        return (reportMallocError());

    s->n = STACK;
    s->prev = NULL;
    s->next = NULL;

    *stack = s;

    return (EXIT_SUCCESS);
}


/**
 * checkMode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int checkMode(stack_t *stack)
{
    if (stack->n == STACK)
        return (STACK);
    else if (stack->n == QUEUE)
        return (QUEUE);
    return (2);
}
