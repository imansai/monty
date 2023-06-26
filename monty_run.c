#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void freeTokens(void);
unsigned int tokenArrLen(void);
int isEmptyLine(char *line, char *delims);
void (*getOpFunc(char *opcode))(stack_t**, unsigned int);
int runMonty(FILE *script_fd);

/**
 * freeTokens - Frees the global array of strings.
 */
void freeTokens(void)
{
    size_t i = 0;

    if (op_toks == NULL)
        return;

    for (i = 0; op_toks[i]; i++)
        free(op_toks[i]);

    free(op_toks);
}

/**
 * tokenArrLen - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int tokenArrLen(void)
{
    unsigned int toks_len = 0;

    while (op_toks[toks_len])
        toks_len++;
    return (toks_len);
}

/**
 * isEmptyLine - Checks if a line read from fgets only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int isEmptyLine(char *line, char *delims)
{
    int i, j;

    for (i = 0; line[i]; i++)
    {
        for (j = 0; delims[j]; j++)
        {
            if (line[i] == delims[j])
                break;
        }
        if (delims[j] == '\0')
            return (0);
    }

    return (1);
}

/**
 * getOpFunc - Matches opcode with corresponding function.
 * @opcode: The opcode to be matched
 *
 * Return: A pointer to the corresponding
 */
void (*getOpFunc(char *opcode))(stack_t**, unsigned int)
{
    instruction_t op_funcs[] = {
        {"push", montyPush},
        {"pall", montyPall},
        {"pint", montyPint},
        {"pop", montyPop},
        {"swap", montySwap},
        {"add", montyAdd},
        {"nop", montyNop},
        {"sub", montySub},
        {"div", montyDiv},
        {"mul", montyMul},
        {"mod", montyMod},
        {"pchar", montyPchar},
        {"pstr", montyPstr},
        {"rotl", montyRotl},
        {"rotr", montyRotr},
        {"stack", montyStack},
        {"queue", montyQueue},
        {NULL, NULL}
    };
    int i;

    for (i = 0; op_funcs[i].opcode; i++)
    {
        if (strcmp(opcode, op_funcs[i].opcode) == 0)
            return (op_funcs[i].f);
    }

    return (NULL);
}

/**
 * runMonty - Primary function to execute Monty script
 * @script_fd: File descriptor for open Monty script
 *
 * Return: EXIT_SUCCESS on success, error code on failure.
 */
int runMonty(FILE *script_fd)
{
    stack_t *stack = NULL;
    char line[MAX_LINE_LENGTH];
    size_t exit_status = EXIT_SUCCESS;
    unsigned int lineNum = 0, prev_tok_len = 0;
    void (*op_func)(stack_t**, unsigned int);

    if (initStack(&stack) == EXIT_FAILURE)
        return (EXIT_FAILURE);

    while (fgets(line, sizeof(line), script_fd) != NULL)
    {
        lineNum++;
        op_toks = strtow(line, DELIMS);
        if (op_toks == NULL)
        {
            if (isEmptyLine(line, DELIMS))
                continue;
            freeStack(&stack);
            return (handleErrorMalloc());
        }
        else if (op_toks[0][0] == '#')
        {
            freeTokens();
            continue;
        }
        op_func = getOpFunc(op_toks[0]);
        if (op_func == NULL)
        {
            freeStack(&stack);
            exit_status = handleErrorUnknownOp(op_toks[0], lineNum);
            freeTokens();
            break;
        }
        prev_tok_len = tokenArrLen();
        op_func(&stack, lineNum);
        if (tokenArrLen() != prev_tok_len)
        {
            if (op_toks && op_toks[prev_tok_len])
                exit_status = atoi(op_toks[prev_tok_len]);
            else
                exit_status = EXIT_FAILURE;
            freeTokens();
            break;
        }
        freeTokens();
    }
    freeStack(&stack);

    if (line[0] == '\0')
    {
        return (handleErrorMalloc());
    }

    return (exit_status);
}
