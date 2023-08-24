#include "monty.h"

/**
 * op_push - Pushes an element onto the stack.
 *
 * @stack: Double pointer to the head of the stack
 * @line_number: The current line number of the code
 */
void op_push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, "\n ");

    if (arg == NULL || !is_number(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(arg);
    push_stack(stack, value); // Push onto the stack
}

/**
 * op_pall - Prints all values on the stack.
 *
 * @stack: Double pointer to the head of the stack
 * @line_number: The current line number of the code
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    stack_t *temp = *stack;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

/**
 * push_stack - Pushes a value onto the stack.
 *
 * @stack: Double pointer to the head of the stack
 * @value: The value to push
 */
void push_stack(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

