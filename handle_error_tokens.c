#include "monty.h"

/**
 * setErrorToken - Sets last element of opTokens to be an error code.
 * @errorCode: Integer to store as a string in opTokens.
 */
void setErrorToken(int errorCode)
{
    int tokensLength = 0;
    int index = 0;
    char *exitStr = NULL;
    char **newTokens = NULL;

    tokensLength = tokenArrLen();
    newTokens = malloc(sizeof(char *) * (tokensLength + 2));
    if (!opTokens)
    {
        reportMallocError();
        return;
    }
    while (index < tokensLength)
    {
        newTokens[index] = opTokens[index];
        index++;
    }
    exitStr = getInt(errorCode);
    if (!exitStr)
    {
        free(newTokens);
        reportMallocError();
        return;
    }
    newTokens[index++] = exitStr;
    newTokens[index] = NULL;
    free(opTokens);
    opTokens = newTokens;
}
