#include "list.h"

t_list	*list_init(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->max_place = 1;
	list->min_place = 1;
	list->max_borne_place = 0;
	return (list);
}

int	list_add_element_head(t_list *list, int new_nb)
{
	t_element	*new;
	t_element	*tmp;

	new = malloc(sizeof(t_element));
	if (list == NULL || new == NULL)
		return (-1);
	new->nb = new_nb;
	if (list->head == NULL)
	{
		list->head = new;
		list->tail = new;
		list->tail->next = NULL;
	}
	else
	{
		tmp = list->head;
		list->head = new;
		list->head->next = tmp;
	}
	return (0);
}

int	list_add_element_tail(t_list *list, int new_nb)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (list == NULL || new == NULL)
		return (-1);
	new->nb = new_nb;
	new->place = 0;
	new->next = NULL;
	if (list->head == NULL)
	{
		list->head = new;
		list->tail = new;
	}
	else
	{
		list->tail->next = new;
		list->tail = new;
	}
	return (0);
}

void	list_display(t_list *list)
{
	t_element	*actual;

	if (list == NULL)
		exit(EXIT_FAILURE);
	actual = list->head;
	while (actual != NULL)
	{
		printf("%d -> ", actual->nb);
		actual = actual->next;
	}
	printf("NULL\n");
}

void	list_dispose(t_list *list)
{
	t_element	*to_free;

	to_free = list->head;
	while (to_free != NULL)
	{
		list->head = to_free->next;
		free(to_free);
		to_free = list->head;
	}
	free(list);
}
