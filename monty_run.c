#include "monty.h"
#include <string.h>


void freeTokens(void);
unsigned int tokenArrLen(void);
int isEmptyLine(char *line, char *delims);
void (*getOpFunction(char *opcode))(stack_t**, unsigned int);
int runMonty(FILE *scriptFd);


/**
 * freeTokens - Frees the global opTokens array of strings.
 */
void freeTokens(void)
{
    size_t index = 0;


    if (opTokens == NULL)
        return;


    for (index = 0; opTokens[index]; index++)
        free(opTokens[index]);


    free(opTokens);
}


/**
 * tokenArrLen - Gets the length of current opTokens.
 *
 * Return: Length of current opTokens (as int).
 */
unsigned int tokenArrLen(void)
{
    unsigned int toksLen = 0;


    while (opTokens[toksLen])
        toksLen++;
    return (toksLen);
}


/**
 * isEmptyLine - Checks if a line read from getline only contains delimiters.
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
 * getOpFunction - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*getOpFunction(char *opcode))(stack_t**, unsigned int)
{
    instruction_t opFunctions[] = {
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
    int index;


    for (index = 0; opFunctions[index].opcode; index++)
    {
        if (strcmp(opcode, opFunctions[index].opcode) == 0)
            return (opFunctions[index].f);
    }


    return (NULL);
}


/**
 * runMonty - Primary function to execute a Monty bytecodes script.
 * @scriptFd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int runMonty(FILE *scriptFd)
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0, exitCode = EXIT_SUCCESS;
    unsigned int lineNum = 0, prevTokLen = 0;
    void (*opFunction)(stack_t**, unsigned int);


    if (initStack(&stack) == EXIT_FAILURE)
        return (EXIT_FAILURE);


    while (getline(&line, &len, scriptFd) != -1)
    {
        lineNum++;
        opTokens = strToWords(line, DELIMS);
        if (opTokens == NULL)
        {
            if (isEmptyLine(line, DELIMS))
                continue;
            freeStack(&stack);
            return (mallocError());
        }
        else if (opTokens[0][0] == '#') /* comment line */
        {
            freeTokens();
            continue;
        }
        opFunction = getOpFunction(opTokens[0]);
        if (opFunction == NULL)
        {
            freeStack(&stack);
            exitCode = unknownOpError(opTokens[0], lineNum);
            freeTokens();
            break;
        }
        prevTokLen = tokenArrLen();
        opFunction(&stack, lineNum);
        if (tokenArrLen() != prevTokLen)
        {
            if (opTokens && opTokens[prevTokLen])
                exitCode = atoi(opTokens[prevTokLen]);
            else
                exitCode = EXIT_FAILURE;
            freeTokens();
            break;
        }
        freeTokens();
    }
    freeStack(&stack);


    if (line && *line == 0)
    {
        free(line);
        return (mallocError());
    }


    free(line);
    return (exitCode);
}
