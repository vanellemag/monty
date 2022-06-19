#include "monty.h"
/**
 * pall_ - print all function
 * @stack: pointer to linked list stack
 *
 */
void pall_(stack_t **stack)
{
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}
/**
 * pint_ - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pint_(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}
/**
 * pop_ - remove element a list
 * @stack: pointer to first node
 * @line_number: integer
 * Return: void
 */
void pop_(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	/**free(nodo);**/
}
