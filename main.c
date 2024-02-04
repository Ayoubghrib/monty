#include "monty.h"
stack_t *head = NULL;

/**
 * Main function - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: Always returns 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_and_read_file(argv[1]);
	cleanup();
	return (0);
}

/**
 * create_node - Creates a new node with the given value.
 * @n: Value to be stored in the new node.
 * Return: Pointer to the newly created node.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * cleanup - Frees all the nodes in the stack.
 */
void cleanup(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * add_to_queue - Adds a new node to the end of the queue.
 * @new_node: Pointer to the new node to be added.
 * @ln: Line number of the opcode (unused).
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}

