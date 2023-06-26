#include "monty.h"


/**
 * setErrorToken - Makes last element of op_toks an error code.
 * @error_code: Int to be stored as string in op_toks.
 */
void setErrorToken(int error_code)
{
    int toks_len = 0, i = 0;
    char *exit_str = NULL;
    char **new_toks = NULL;


    toks_len = tokenArrLen();
    new_toks = malloc(sizeof(char *) * (toks_len + 2));
    if (!op_toks)
    {
        handleErrorMalloc();
        return;
    }
    while (i < toks_len)
    {
        new_toks[i] = op_toks[i];
        i++;
    }
    exit_str = getInt(error_code);
    if (!exit_str)
    {
        free(new_toks);
        handleErrorMalloc();
        return;
    }
    new_toks[i++] = exit_str;
    new_toks[i] = NULL;
    free(op_toks);
    op_toks = new_toks;
}
