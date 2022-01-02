#include "pushswap.h"

int	sa(t_list *stack_a)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
	{
		return (-1);
	}
	else
	{
		list_swap_heads(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	return (0);
}

int	sb(t_list *stack_b)
{
	if (stack_b->head == NULL || stack_b->head->next == NULL)
	{
		return (-1);
	}
	else
	{
		list_swap_heads(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
	return (0);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

int	pa(t_list *stack_b, t_list *stack_a)
{
	if (stack_b->head == NULL)
	{
		return (-1);
	}
	else
	{
		list_push(stack_b, stack_a);
		ft_putstr_fd("pa\n", 1);
	}
	return (0);
}

int	pb(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->head == NULL)
	{
		return (-1);
	}
	else
	{
		list_push(stack_a, stack_b);
		ft_putstr_fd("pb\n", 1);
	}
	return (0);
}
