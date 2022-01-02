#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stddef.h>
# include <unistd.h>
# include "list/list.h"
# include <limits.h>

size_t			ft_strlen(const char *str);
void			*ft_memcpy(void *dest, const void *src, size_t num);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			**ft_split(char const *s, char c);
long long int	ft_atoll(const char *str);
int				free_tab(char **tab);
int				get_args(int argc, char **argv, t_list *list);
void			ft_putstr_fd(char *s, int fd);
int				sa(t_list *stack_a);
int				sb(t_list *stack_b);
void			ss(t_list *stack_a, t_list *stack_b);
int				pa(t_list *stack_b, t_list *stack_a);
int				pb(t_list *stack_a, t_list *stack_b);
int				ra(t_list *stack_a);
int				rb(t_list *stack_b);
void			rr(t_list *stack_a, t_list *stack_b);
int				rra(t_list *stack_a);
int				rrb(t_list *stack_b);
void			rrr(t_list *stack_a, t_list *stack_b);
int				min_stack_a(t_list *stack_a);
int				max_stack_a(t_list *stack_a);
int				max_borne(t_list *stack_a, t_list *stack_b);
void			rotate_min_to_top(t_list *stack_a);
void			rotate_max_to_bottom(t_list *stack_a);
void			rotate_max_borne_to_top(t_list *stack_a, t_list *stack_b);
int				algo_three_numbers(t_list *stack_a);
int				algo_five_numbers(t_list *stack_a, t_list *stack_b);
void			radix_sort(t_list *stack_a, t_list *stack_b);

#endif