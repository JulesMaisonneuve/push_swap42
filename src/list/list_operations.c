#include "list.h"

void	list_swap_heads(t_list *list)
{
	t_element	*tmp;
	t_element	*third;

	tmp = list->head;
	list->head = list->head->next;
	third = list->head->next;
	tmp->next = third;
	list->head->next = tmp;
	if (list_len(list) == 2)
	{
		list->tail = tmp;
	}
}

void	list_rotate(t_list *list)
{
	t_element	*tmp_head;

	tmp_head = list->head;
	list->head = list->head->next;
	list->tail->next = tmp_head;
	list->tail = tmp_head;
	list->tail->next = NULL;
}

void	list_reverse_rotate(t_list *list)
{
	t_element	*actual;
	t_element	*penultimate;
	t_element	*tmp_head;

	actual = list->head;
	while (actual->next != list->tail)
	{
		actual = actual->next;
	}
	penultimate = actual;
	tmp_head = list->head;
	list->head = list->tail;
	list->head->next = tmp_head;
	list->tail = penultimate;
	list->tail->next = NULL;
}

void	list_push(t_list *stack_src, t_list *stack_dst)
{
	t_element	*tmp_b;
	t_element	*tmp_a;

	if (stack_dst->head == NULL)
	{
		tmp_a = stack_src->head->next;
		stack_dst->head = stack_src->head;
		stack_dst->tail = stack_dst->head;
		stack_dst->head->next = NULL;
		stack_src->head = tmp_a;
	}
	else
	{
		tmp_b = stack_dst->head;
		tmp_a = stack_src->head->next;
		stack_dst->head = stack_src->head;
		stack_src->head = tmp_a;
		stack_dst->head->next = tmp_b;
	}
	if (list_len(stack_src) == 0)
	{
		stack_src->tail = NULL;
	}
}
