//
// Created by Remi BARBERO on 7/23/17.
//

#include <stdlib.h>
#include "../includes/ft_stack.h"

t_stack	*ft_stack_create(int size)
{
	t_stack *stack;

	if (!(stack = malloc(sizeof(t_stack) * size)))
		return (0);
	stack->top = 0;
	stack->size = size;
	return (stack);
}

void ft_stack_add(t_stack *stack, void *data)
{
	if (stack->top < stack->size)
	{
		stack->data = data;
		stack->top++;
	}
}

void ft_stack_add_nbr(t_stack *stack, int data)
{
	if (stack->top < stack->size)
	{
		if(!(stack->data = malloc(sizeof(int))))
			return ;
		*((int *)stack->data) = data;
		stack->top++;
	}
}

void ft_stack_add_char(t_stack *stack, char data)
{
	if (stack->top < stack->size)
	{
		if(!(stack->data = malloc(sizeof(char))))
			return ;
		*((int *)stack->data) = data;
		stack->top++;
	}
}

void *ft_stack_pop(t_stack *stack)
{
	void *tmp;

	tmp = 0;
	if (stack->top > 0) {
		tmp = stack[stack->top].data;
		stack->top--;
	}
	return (tmp);
}

int ft_stack_size(t_stack *stack)
{
	return (stack->top);
}
