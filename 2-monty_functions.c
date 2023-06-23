#include "monty.h"

void monty_add(stack_t **stack, unsigned int lineNum);
void monty_sub(stack_t **stack, unsigned int lineNum);
void monty_div(stack_t **stack, unsigned int lineNum);
void monty_mul(stack_t **stack, unsigned int lineNum);
void monty_mod(stack_t **stack, unsigned int lineNum);

/**
 * monty_add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_add(stack_t **stack, unsigned int lineNum)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(lineNum, "add"));
        return;
    }

    (*stack)->next->next->n += (*stack)->next->n;
    monty_pop(stack, lineNum);
}

/**
 * monty_sub - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_sub(stack_t **stack, unsigned int lineNum)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(lineNum, "sub"));
        return;
    }

    (*stack)->next->next->n -= (*stack)->next->n;
    monty_pop(stack, lineNum);
}

/**
 * monty_div - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_div(stack_t **stack, unsigned int lineNum)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(lineNum, "div"));
        return;
    }

    if ((*stack)->next->n == 0)
    {
        set_op_tok_error(div_error(lineNum));
        return;
    }

    (*stack)->next->next->n /= (*stack)->next->n;
    monty_pop(stack, lineNum);
}

/**
 * monty_mul - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_mul(stack_t **stack, unsigned int lineNum)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(lineNum, "mul"));
        return;
    }

    (*stack)->next->next->n *= (*stack)->next->n;
    monty_pop(stack, lineNum);
}

/**
 * monty_mod - Computes the modulus of the second value from the
 *             top of a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_mod(stack_t **stack, unsigned int lineNum)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(lineNum, "mod"));
        return;
    }

    if ((*stack)->next->n == 0)
    {
        set_op_tok_error(div_error(lineNum));
        return;
    }

    (*stack)->next->next->n %= (*stack)->next->n;
    monty_pop(stack, lineNum);
}
