#include "monty.h"

void montyPush(stack_t **stack, unsigned int lineNumber);
void montyPall(stack_t **stack, unsigned int lineNumber);
void montyPint(stack_t **stack, unsigned int lineNumber);
void montyPop(stack_t **stack, unsigned int lineNumber);
void montySwap(stack_t **stack, unsigned int lineNumber);

/**
 * montyPush - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNumber: The current working line number of a Monty bytecodes file.
 */
void montyPush(stack_t **stack, unsigned int lineNumber)
{
    stack_t *tempNode, *newNode;
    int i;

    newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        setOpTokError(mallocError());
        return;
    }

    if (opToks[1] == NULL)
    {
        setOpTokError(noIntError(lineNumber));
        return;
    }

    for (i = 0; opToks[1][i]; i++)
    {
        if (opToks[1][i] == '-' && i == 0)
            continue;
        if (opToks[1][i] < '0' || opToks[1][i] > '9')
        {
            setOpTokError(noIntError(lineNumber));
            return;
        }
    }
    newNode->n = atoi(opToks[1]);

    if (checkMode(*stack) == STACK) /* STACK mode insert at front */
    {
        tempNode = (*stack)->next;
        newNode->prev = *stack;
        newNode->next = tempNode;
        if (tempNode)
            tempNode->prev = newNode;
        (*stack)->next = newNode;
    }
    else /* QUEUE mode insert at end */
    {
        tempNode = *stack;
        while (tempNode->next)
            tempNode = tempNode->next;
        newNode->prev = tempNode;
        newNode->next = NULL;
        tempNode->next = newNode;
    }
}

/**
 * montyPall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNumber: The current working line number of a Monty bytecodes file.
 */
void montyPall(stack_t **stack, unsigned int lineNumber)
{
    stack_t *tempNode = (*stack)->next;

    while (tempNode)
    {
        printf("%d\n", tempNode->n);
        tempNode = tempNode->next;
    }
    (void)lineNumber;
}

/**
 * montyPint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNumber: The current working line number of a Monty bytecodes file.
 */
void montyPint(stack_t **stack, unsigned int lineNumber)
{
    if ((*stack)->next == NULL)
    {
        setOpTokError(pintError(lineNumber));
        return;
    }

    printf("%d\n", (*stack)->next->n);
}

/**
 * montyPop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNumber: The current working line number of a Monty bytecodes file.
 */
void montyPop(stack_t **stack, unsigned int lineNumber)
{
    stack_t *next = NULL;

    if ((*stack)->next == NULL)
    {
        setOpTokError(popError(lineNumber));
        return;
    }

    next = (*stack)->next->next;
    free((*stack)->next);
    if (next)
        next->prev = *stack;
    (*stack)->next = next;
}

/**
 * montySwap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNumber: The current working line number of a Monty bytecodes file.
 */
void montySwap(stack_t **stack, unsigned int lineNumber)
{
    stack_t *tempNode;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        setOpTokError(shortStackError(lineNumber, "swap"));
        return;
    }

    tempNode = (*stack)->next->next;
    (*stack)->next->next = tempNode->next;
    (*stack)->next->prev = tempNode;
    if (tempNode->next)
        tempNode->next->prev = (*stack)->next;
    tempNode->next = (*stack)->next;
    tempNode->prev = *stack;
    (*stack)->next = tempNode;
}
