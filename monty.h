#ifndef __MONTY_H__
#define __MONTY_H__


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"


/* GLOBAL OPCODE TOKENS */
extern char **op_toks;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int lineNum);
} instruction_t;


/* PRIMARY INTERPRETER FUNCTIONS */
void freeStack(stack_t **stack);
int initStack(stack_t **stack);
int checkMode(stack_t *stack);
void freeTokens(void);
unsigned int tokenArrLen(void);
int runMonty(FILE *script_fd);
void setErrorToken(int error_code);


/* OPCODE FUNCTIONS */
void montyPush(stack_t **stack, unsigned int lineNum);
void montyPall(stack_t **stack, unsigned int lineNum);
void montyPint(stack_t **stack, unsigned int lineNum);
void montyPop(stack_t **stack, unsigned int lineNum);
void montySwap(stack_t **stack, unsigned int lineNum);
void montyAdd(stack_t **stack, unsigned int lineNum);
void montyNop(stack_t **stack, unsigned int lineNum);
void montySub(stack_t **stack, unsigned int lineNum);
void montyDiv(stack_t **stack, unsigned int lineNum);
void montyMul(stack_t **stack, unsigned int lineNum);
void montyMod(stack_t **stack, unsigned int lineNum);
void montyPchar(stack_t **stack, unsigned int lineNum);
void montyPstr(stack_t **stack, unsigned int lineNum);
void montyRotl(stack_t **stack, unsigned int lineNum);
void montyRotr(stack_t **stack, unsigned int lineNum);
void montyStack(stack_t **stack, unsigned int lineNum);
void montyQueue(stack_t **stack, unsigned int lineNum);


/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *getInt(int n);


/* ERROR MESSAGES & ERROR CODES */
int handleErrorUsage(void);
int handleErrorMalloc(void);
int handleErrorFileOpen(char *filename);
int handleErrorUnknownOp(char *opcode, unsigned int lineNum);
int handleErrorNoInt(unsigned int lineNum);
int handleErrorPop(unsigned int lineNum);
int handleErrorPint(unsigned int lineNum);
int handleErrorShortStack(unsigned int lineNum, char *op);
int handleErrorDiv(unsigned int lineNum);
int handleErrorPChar(unsigned int lineNum, char *message);


#endif /* __MONTY_H__ */
