#include "monty.h"

/**
 * multiply_nodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void multiply_nodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "multiply");

	(*stack) = (*stack)->next;
	result = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * modulo_nodes - Computes the modulo of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void modulo_nodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "modulo");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	result = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

