::fndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * struct data_s - all data
  * @fd: the stream pointer
  *@in_line: the input line from getline
  *@arg: the second tok from in_line
  *@stack: the first element of the stack
  *@line_nb: the input line counter
  *@inst: the array of struct instruction_t
  **/
typedef struct	data_s
{
	FILE		*fd;
	char		*in_line;
	char		*arg;
	stack_t		*stack;
	unsigned int		line_nb;
	instruction_t	*inst;
}		data_t;

extern data_t data;

/* In main.c */
void	monty(FILE *fd);

/* In execute.c */
void	execute(char *cmd);

/* In commands.c */
void	push(stack_t **stack, unsigned int line_number);
void	pall(stack_t **stack, unsigned int line_number);
void	pint(stack_t **stack, unsigned int line_number);
void	swap(stack_t **stack, unsigned int line_number);
void	nop(stack_t **stack, unsigned int line_number);
void	div_op(stack_t **stack, unsigned int line_number);
void	mod_op(stack_t **stack, unsigned int line_number);
void	pchar(stack_t **stack, unsigned int line_number);
void	rotl(stack_t **stack, unsigned int line_number);

/* In commands2.c */
void	pop(stack_t **stack, unsigned int line_number);
void	add(stack_t **stack, unsigned int line_number);
void	sub(stack_t **stack, unsigned int line_number);
void	mul(stack_t **stack, unsigned int line_number);

/* In clean.c */
void	clean(void);

/* In stack_funcs.c */
stack_t		*create_node(int n);
stack_t		*add_node(stack_t **head, stack_t *node);
stack_t		*add_node_end(stack_t **head, stack_t *node);
void		delete_node(stack_t **head, stack_t *node);
size_t stack_len(stack_t *head);

int	isnum(char *s);

#endif
