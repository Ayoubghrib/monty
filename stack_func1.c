#include "monty.h"

/**
 * add_node_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @line_number: Integer representing the line number of the opcode.
 */
void add_node_to_stack(stack_t **new_node, __attribute__((unused))unsigned int line_number)
{
    stack_t *tmp;

    if (new_node == NULL || *new_node == NULL)
        exit(EXIT_FAILURE);
    if (head == NULL)
    {
        head = *new_node;
        return;
    }
    tmp = head;
    head = *new_node;
    head->next = tmp;
    tmp->prev = head;
}

/**
 * print_stack - Prints the contents of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    (void) line_number; // Unused parameter
    if (stack == NULL)
        exit(EXIT_FAILURE);
    tmp = *stack;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

/**
 * pop_top - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL)
        more_err(7, line_number); // Error handling
    tmp = *stack;
    *stack = tmp->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(tmp);
}

/**
 * print_top - Prints the value of the top node of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL)
        more_err(6, line_number); // Error handling
    printf("%d\n", (*stack)->n);
}

