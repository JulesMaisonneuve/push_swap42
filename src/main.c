#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		len;

	if (argc < 2)
		return (-1);
	list_a = list_init();
	list_b = list_init();
	len = 0;
	if (get_args(argc, argv, list_a) == -1)
	{
		list_dispose(list_b);
		return (-1);
	}
	len = list_len(list_a);
	if (len == 2 || len == 3)
		algo_three_numbers(list_a);
	else if (len == 4 || len == 5)
		algo_five_numbers(list_a, list_b);
	else
		radix_sort(list_a, list_b);
	list_display(list_a);
	list_dispose(list_a);
	list_dispose(list_b);
	return (0);
}
