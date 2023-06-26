#include "monty.h"


int handleErrorUsage(void);
int handleErrorMalloc(void);
int handleErrorFileOpen(char *filename);
int handleErrorUnknownOp(char *opcode, unsigned int lineNum);
int handleErrorNoInt(unsigned int lineNum);


/**
 * handleErrorUsage - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorUsage(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    return (EXIT_FAILURE);
}


/**
 * handleErrorMalloc - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorMalloc(void)
{
    fprintf(stderr, "Error: malloc failed\n");
    return (EXIT_FAILURE);
}


/**
 * handleErrorFileOpen - Prints file opening error messages
 * @filename: Name of file that failed to open.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorFileOpen(char *filename)
{
    fprintf(stderr, "Error: File can't be opened %s\n", filename);
    return (EXIT_FAILURE);
}


/**
 * handleErrorUnknownOp - Prints file opening error messages.
 * @opcode: Opcode where error occurred.
 * @lineNum: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorUnknownOp(char *opcode, unsigned int lineNum)
{
    fprintf(stderr, "L%u: unknown instruction %s\n",
        lineNum, opcode);
    return (EXIT_FAILURE);
}


/**
 * handleErrorNoInt - Prints invalid monty_push argument error messages.
 * @lineNum: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleErrorNoInt(unsigned int lineNum)
{
    fprintf(stderr, "L%u: usage: push integer\n", lineNum);
    return (EXIT_FAILURE);
}
