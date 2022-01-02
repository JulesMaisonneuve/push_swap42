#include "pushswap.h"

int	ra(t_list *stack_a)
{
	if (stack_a->head == NULL || stack_a->head->next == NULL)
	{
		return (-1);
	}
	else
	{
		list_rotate(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	return (0);
}

int	rb(t_list *stack_b)
{
	if (stack_b->head == NULL || stack_b->head->next == NULL)
	{
		return (-1);
	}
	else
	{
		list_rotate(stack_b);
		ft_putstr_fd("rb\n", 1);
	}
	return (0);
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
