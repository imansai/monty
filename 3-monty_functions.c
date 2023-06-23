#include "monty.h"

void montyNop(stack_t **stack, unsigned int lineNum);
void montyPchar(stack_t **stack, unsigned int lineNum);
void montyPstr(stack_t **stack, unsigned int lineNum);

/**
 * montyNop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void montyNop(stack_t **stack, unsigned int lineNum)
{
    (void)stack;
    (void)lineNum;
}

/**
 * montyPchar - Prints the character in the top value
 *              node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void montyPchar(stack_t **stack, unsigned int lineNum)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pchar_error(lineNum, "stack empty"));
        return;
    }
    if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
    {
        set_op_tok_error(pchar_error(lineNum, "value out of range"));
        return;
    }

    printf("%c\n", (*stack)->next->n);
}

/**
 * montyPstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void montyPstr(stack_t **stack, unsigned int lineNum)
{
    stack_t *tmp = (*stack)->next;

    while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
    {
        printf("%c", tmp->n);
        tmp = tmp->next;
    }

    printf("\n");

    (void)lineNum;
}
