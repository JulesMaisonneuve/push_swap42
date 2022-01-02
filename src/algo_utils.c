#include "pushswap.h"

int	min_stack_a(t_list *stack_a)
{
	t_element	*actual;
	int			min;
	int			i;

	i = 1;
	stack_a->min_place = i;
	actual = stack_a->head;
	min = actual->nb;
	while (actual != NULL)
	{
		if (actual->nb < min)
		{
			min = actual->nb;
			stack_a->min_place = i;
		}
		actual = actual->next;
		i++;
	}
	return (min);
}

int	max_stack_a(t_list *stack_a)
{
	t_element	*actual;
	int			max;
	int			i;

	i = 1;
	stack_a->max_place = i;
	actual = stack_a->head;
	max = actual->nb;
	while (actual != NULL)
	{
		if (actual->nb > max)
		{
			max = actual->nb;
			stack_a->max_place = i;
		}
		actual = actual->next;
		i++;
	}
	return (max);
}

int	max_borne(t_list *stack_a, t_list *stack_b)
{
	t_element	*actual;
	int			max_borne;
	int			i;

	i = 1;
	max_borne = INT_MAX;
	actual = stack_a->head;
	while (actual != NULL)
	{
		if (actual->nb > stack_b->head->nb && actual->nb < max_borne)
		{
			max_borne = actual->nb;
			stack_a->max_borne_place = i;
		}
		actual = actual->next;
		i++;
	}
	return (max_borne);
}

void	rotate_min_to_top(t_list *stack_a)
{
	while (stack_a->head->nb != min_stack_a(stack_a))
	{
		if (stack_a->min_place > 3
			|| (stack_a->min_place == 3 && list_len(stack_a) == 4))
			rra(stack_a);
		else
		{
			ra(stack_a);
		}
	}
}

void	rotate_max_to_bottom(t_list *stack_a)
{
	while (stack_a->tail->nb != max_stack_a(stack_a))
	{
		if (stack_a->max_place >= 3
			|| (stack_a->max_place == 3 && list_len(stack_a) == 4))
			rra(stack_a);
		else
		{
			ra(stack_a);
		}
	}
}
