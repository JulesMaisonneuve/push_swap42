#include "pushswap.h"

int	rra(t_list *stack_a)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
	{
		return (-1);
	}
	else
	{
		list_reverse_rotate(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	return (0);
}

int	rrb(t_list *stack_b)
{
	if (stack_b->head == NULL || stack_b->head->next == NULL)
	{
		return (-1);
	}
	else
	{
		list_reverse_rotate(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
	return (0);
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
