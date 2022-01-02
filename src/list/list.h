#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_element {
	int					nb;
	int					place;
	struct s_element	*next;
}				t_element;

typedef struct s_list {
	t_element	*head;
	t_element	*tail;
	int			min_place;
	int			max_place;
	int			max_borne_place;
}				t_list;

t_list	*list_init(void);
void	list_swap_heads(t_list *list);
void	list_rotate(t_list *list);
void	list_reverse_rotate(t_list *list);
void	list_push(t_list *stack_src, t_list *stack_dst);
int		list_add_element_head(t_list *list, int new_nb);
int		list_add_element_tail(t_list *list, int new_nb);
void	list_display(t_list *list);
void	list_dispose(t_list *list);
int		is_list_sorted(t_list *stack_a);
int		list_len(t_list *list);

#endif