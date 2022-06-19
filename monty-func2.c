#include "monty.h"
/**
 * push_ - push int to a stack
 * @stack: linked lists for monty stack
 * @value: number of line opcode occurs on
 */
void push_(stack_t **stack, unsigned int value)
{
	stack_t *top;
	/**(void)line_number;**/

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	top->n = value;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}
