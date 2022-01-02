#include "pushswap.h"

int	algo_three_numbers(t_list *stack_a)
{
	while (is_list_sorted(stack_a) != 1)
	{
		if (stack_a->head->nb < stack_a->head->next->nb
			&& stack_a->head->nb > stack_a->tail->nb)
		{
			rra(stack_a);
		}
		else if (stack_a->head->nb > stack_a->head->next->nb
			&& stack_a->head->nb > stack_a->tail->nb)
		{
			ra(stack_a);
		}
		else
		{
			sa(stack_a);
		}
	}
	return (0);
}

int	algo_five_numbers(t_list *stack_a, t_list *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	algo_three_numbers(stack_a);
	while (list_len(stack_b) != 0)
	{
		if (stack_b->head->nb < min_stack_a(stack_a))
		{
			rotate_min_to_top(stack_a);
		}
		else if (stack_b->head->nb > max_stack_a(stack_a))
		{
			rotate_max_to_bottom(stack_a);
		}
		else
		{
			rotate_max_borne_to_top(stack_a, stack_b);
		}
		pa(stack_b, stack_a);
	}
	rotate_min_to_top(stack_a);
	return (0);
}

void	radix_sort(t_list *stack_a, t_list *stack_b)
{
	int	size;
	int	max_num;
	int	max_bits;
	int	i;
	int	j;

	size = list_len(stack_a);
	max_num = size - 1;
	max_bits = 0;
	i = -1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((stack_a->head->place >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (list_len(stack_b) != 0)
			pa(stack_b, stack_a);
	}
}
