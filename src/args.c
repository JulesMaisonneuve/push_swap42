#include "pushswap.h"

int	is_valid_arg(char *arg)
{
	while (*arg)
	{
		if ((*arg < '0' || *arg > '9') && (*arg != '-' && *arg != '+'))
		{
			ft_putstr_fd("Error\n", 1);
			return (-1);
		}
		else if ((*arg == '-' && *(arg + 1) == '-')
			|| (*arg == '+' && *(arg + 1) == '+'))
		{
			ft_putstr_fd("Error\n", 1);
			return (-1);
		}
		else if ((*arg == '-' || *arg == '+') && *(arg + 1) == '\0')
		{
			ft_putstr_fd("Error\n", 1);
			return (-1);
		}
		arg++;
	}
	return (0);
}

void	get_update_place(t_list *list)
{
	t_element	*actual;

	actual = list->head;
	while (actual != NULL)
	{
		if (list->tail->nb >= actual->nb)
			list->tail->place++;
		else
			actual->place++;
		actual = actual->next;
	}
}

int	check_for_duplicate(t_list *list, int new_nb)
{
	t_element	*actual;

	actual = list->head;
	while (actual != NULL)
	{
		if (actual->nb == new_nb)
		{
			return (-1);
		}
		actual = actual->next;
	}
	return (0);
}

int	fill_stack(char **tab, t_list *list)
{
	int				i;
	long long int	nb;

	i = 0;
	nb = 0;
	while (tab[i])
	{
		if (is_valid_arg(tab[i]) == -1)
		{
			list_dispose(list);
			return (-1);
		}
		nb = ft_atoll(tab[i]);
		if ((nb > 2147483647 || nb < -2147483648)
			|| check_for_duplicate(list, (int)nb) == -1)
		{
			ft_putstr_fd("Error\n", 1);
			list_dispose(list);
			return (-1);
		}
		list_add_element_tail(list, (int)nb);
		get_update_place(list);
		i++;
	}
	return (0);
}

int	get_args(int argc, char **argv, t_list *list)
{
	char	**tab;
	int		i;

	i = 1;
	while (i < argc)
	{
		tab = ft_split(argv[i], ' ');
		if (fill_stack(tab, list) == -1)
		{
			free_tab(tab);
			return (-1);
		}
		free_tab(tab);
		i++;
	}
	return (0);
}
