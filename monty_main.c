#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **opTokens = NULL;

/**
 * main - The entry point for Monty Interpreter.
 *
 * @argc: The count of arguments passed to the program.
 * @argv: Pointer to an array of character pointers to arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int argc, char **argv)
{
    FILE *scriptFile = NULL;
    int exitCode = EXIT_SUCCESS;

    if (argc != 2)
        return (usageError());
    scriptFile = fopen(argv[1], "r");
    if (scriptFile == NULL)
        return (fopenError(argv[1]));
    exitCode = runMonty(scriptFile);
    fclose(scriptFile);
    return (exitCode);
}
