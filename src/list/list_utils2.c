#include "list.h"

int	is_list_sorted(t_list *stack_a)
{
	t_element	*actual;

	actual = stack_a->head;
	while (actual->next != NULL)
	{
		if (actual->nb > actual->next->nb)
		{
			return (-1);
		}
		else
		{
			actual = actual->next;
		}
	}
	return (1);
}

int	list_len(t_list *list)
{
	t_element	*actual;
	int			i;

	actual = list->head;
	i = 0;
	while (actual != NULL)
	{
		actual = actual->next;
		i++;
	}
	return (i);
}
