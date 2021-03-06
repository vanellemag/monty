#ifndef _MONTY_H_
#define _MONTY_H
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stddef.h>
#include <errno.h>
extern int push_arg;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 *
 * Description: doublly linked list node structure
 * for stack, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global_variable - opcode and its function
 * @file: the opcode
 * @push_arg: function to handle the opcode
 * @buffer: pointer to
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holbeeton project
 */
typedef struct global_variable
{
	FILE *file;
	int push_arg;
	char *buffer;
} global_var;
extern global_var var_global;
void push_(stack_t **stack, unsigned int line);
void pall_(stack_t **stack, unsigned int line);
void pint_(stack_t **stack, unsigned int line);
void pop_(stack_t  **stack, unsigned int line);
void nop_(stack_t **stack, unsigned int line);
void swap_(stack_t **stack, unsigned int line);
void rotl_(stack_t **stack, unsigned int line);
void rotr_(stack_t **stack, unsigned int line);

void read_file(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *str);

void free_dlistint(stack_t *head);
void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);
int _isalpha(int c);

void pchar_(stack_t **stack, unsigned int line);
void pstr_(stack_t **stack, unsigned int line);

void sub_(stack_t **stack, unsigned int line);
void add_(stack_t **stack, unsigned int line);
void mul_(stack_t **stack, unsigned int line);
void div_(stack_t **stack, unsigned int line);
void mod_(stack_t **stack, unsigned int line);
#endif /*_MONTY_H*/
