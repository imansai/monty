#include "monty.h"

/**
 * handleErrorShortStack - Prints short stack error messages.
 * @lineNum: Line number where the error occurred.
 * @operation: The operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorShortStack(unsigned int lineNum, char *operation)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", lineNum, operation);
	return (EXIT_FAILURE);
}

/**
 * handleErrorDiv - Prints division error messages for division by 0.
 * @lineNum: Line number where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorDiv(unsigned int lineNum)
{
	fprintf(stderr, "L%u: division by zero\n", lineNum);
	return (EXIT_FAILURE);
}

/**
 * handleErrorPop - Prints pop error messages for empty stacks.
 * @lineNum: Line number where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorPop(unsigned int lineNum)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", lineNum);
	return (EXIT_FAILURE);
}

/**
 * handleErrorPChar - Prints pchar error messages.
 * @lineNum: Line number where the error occurred.
 * @errorMsg: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorPChar(unsigned int lineNum, char *errorMsg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", lineNum, errorMsg);
	return (EXIT_FAILURE);
}

/**
 * handleErrorPint - Prints pint error messages for empty stacks.
 * @lineNum: Line number where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorPint(unsigned int lineNum)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", lineNum);
	return (EXIT_FAILURE);
}
