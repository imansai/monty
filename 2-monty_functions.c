#include "monty.h"


void montyAdd(stack_t **stack, unsigned int lineNum);
void montySub(stack_t **stack, unsigned int lineNum);
void montyDiv(stack_t **stack, unsigned int lineNum);
void montyMul(stack_t **stack, unsigned int lineNum);
void montyMod(stack_t **stack, unsigned int lineNum);


/**
 * montyAdd - Adds the top two values of alinked list.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void montyAdd(stack_t **stack, unsigned int lineNum)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        setErrorToken(handleErrorShortStack(lineNum, "add"));
        return;
    }


    (*stack)->next->next->n += (*stack)->next->n;
    montyPop(stack, lineNum);
}


/**
 * montySub - Subtracts the second value from the top of
 *             alinked list by the top value.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void montySub(stack_t **stack, unsigned int lineNum)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        setErrorToken(handleErrorShortStack(lineNum, "sub"));
        return;
    }


    (*stack)->next->next->n -= (*stack)->next->n;
    montyPop(stack, lineNum);
}


/**
 * montyDiv - Divides the second value from the top of
 *             alinked list by the top value.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void montyDiv(stack_t **stack, unsigned int lineNum)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        setErrorToken(handleErrorShortStack(lineNum, "div"));
        return;
    }


    if ((*stack)->next->n == 0)
    {
        setErrorToken(handleErrorDiv(lineNum));
        return;
    }


    (*stack)->next->next->n /= (*stack)->next->n;
    montyPop(stack, lineNum);
}


/**
 * montyMul - Multiplies the second value from the top of
 *             alinked list by the top value.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void montyMul(stack_t **stack, unsigned int lineNum)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        setErrorToken(handleErrorShortStack(lineNum, "mul"));
        return;
    }


    (*stack)->next->next->n *= (*stack)->next->n;
    montyPop(stack, lineNum);
}


/**
 * montyMod - Computes the modulus of the second value from the
 *             top of alinked list  by the top value.
 * @stack: A pointer to the top mode node of alinked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void montyMod(stack_t **stack, unsigned int lineNum)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        setErrorToken(handleErrorShortStack(lineNum, "mod"));
        return;
    }


    if ((*stack)->next->n == 0)
    {
        setErrorToken(handleErrorDiv(lineNum));
        return;
    }


    (*stack)->next->next->n %= (*stack)->next->n;
    montyPop(stack, lineNum);
}
