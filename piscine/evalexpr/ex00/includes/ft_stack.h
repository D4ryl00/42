//
// Created by Remi BARBERO on 7/23/17.
//

#ifndef FT_STACK_H
#define FT_STACK_H

typedef struct	s_stack
{
	int		top;
	int 	size;
	void	*data;
}				t_stack;

t_stack	*ft_stack_create(int size);
void ft_stack_add(t_stack *stack, void *data);
void ft_stack_add_nbr(t_stack *stack, int data);
void ft_stack_add_char(t_stack *stack, char data);
void *ft_stack_pop(t_stack *stack);
int ft_stack_size(t_stack *stack);

#endif
