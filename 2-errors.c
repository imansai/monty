#include "monty.h"


int handleErrorShortStack(unsigned int lineNum, char *op);
int handleErrorDiv(unsigned int lineNum);
int handleErrorPop(unsigned int lineNum);
int handleErrorPint(unsigned int lineNum);
int handleErrorPChar(unsigned int lineNum, char *message);


/**
 * handleErrorPop - Prints pop error messages for empty stacks.
 * @lineNum: Line number in script where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorPop(unsigned int lineNum)
{
    fprintf(stderr, "L%u: can't pop an empty stack\n", lineNum);
    return (EXIT_FAILURE);
}


/**
 * handleErrorPint - Prints pint error messages for empty stacks.
 * @lineNum: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorPint(unsigned int lineNum)
{
    fprintf(stderr, "L%d: can't pint, stack empty\n", lineNum);
    return (EXIT_FAILURE);
}


/**
 * handleErrorShortStack - Prints monty math function error messages
 *                     for stacks/queues smaller than two nodes.
 * @lineNum: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorShortStack(unsigned int lineNum, char *op)
{
    fprintf(stderr, "L%u: can't %s, stack too short\n", lineNum, op);
    return (EXIT_FAILURE);
}


/**
 * handleErrorDiv - Prints error messages for division by 0.
 * @lineNum: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorDiv(unsigned int lineNum)
{
    fprintf(stderr, "L%u: division by zero\n", lineNum);
    return (EXIT_FAILURE);
}


/**
 * handleErrorPChar - Prints pchar error messages for empty stacks
 * @lineNum: Line number in Monty bytecodes file where error occurred.
 * @message: Corresponding error message to be printed
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorPChar(unsigned int lineNum, char *message)
{
    fprintf(stderr, "L%u: can't pchar, %s\n", lineNum, message);
    return (EXIT_FAILURE);
}
