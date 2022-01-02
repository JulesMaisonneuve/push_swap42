#include "pushswap.h"

void	rotate_max_borne_to_top(t_list *stack_a, t_list *stack_b)
{
	while (stack_a->head->nb != max_borne(stack_a, stack_b))
	{
		if (stack_a->max_borne_place > 3
			|| (stack_a->max_borne_place == 3 && list_len(stack_a) == 4))
			rra(stack_a);
		else
		{
			ra(stack_a);
		}
	}
}
