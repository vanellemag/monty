#include "monty.h"
/**
 * push_ - push an element to the stack
 * @stack: linked lists for monty stack
 * @line: number of line opcode occurs on
 */
void push_(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *top;
	(void)line;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	top->n = var_global.push_arg;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}
/**
 * pall_ - print all the value on the stack, starting from the
 * top of the stack.
 * @stack: pointer to linked list stack
 * @line: number of line opcode occurs on
 */
void pall_(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}
/**
 * pint_ - print int a top of stack
 * @stack: pointer to linked list stack
 * @line: number of line opcode occurs on
 */
void pint_(stack_t **stack, unsigned int line)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't  pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}
/**
 * pop_ - remove element a list
 * @stack: pointer to first node
 * @line: integer
 * Return: void
 */
void pop_(stack_t **stack, unsigned int line)
{
	stack_t *nodo = *stack;

	if (*stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}
/**
 * free_dlistint - free a list
 * @head: pointer to first node
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
