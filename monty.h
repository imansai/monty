#include "monty.h"

void monty_nop(stack_t **stack, unsigned int lineNum);
void monty_pchar(stack_t **stack, unsigned int lineNum);
void monty_pstr(stack_t **stack, unsigned int lineNum);

/**
 * monty_nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int lineNum)
{
    (void)stack;
    (void)lineNum;
}

/**
 * monty_pchar - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int lineNum)
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
 * monty_pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void monty_pstr(stack_t **stack, unsigned int lineNum)
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
