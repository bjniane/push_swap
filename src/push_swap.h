/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:57:46 by bjniane           #+#    #+#             */
/*   Updated: 2024/06/02 15:48:46 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}					t_stack;

size_t				ft_strlen(const char *str);
int					main(int ac, char **av);
int					ft_atoi(const char *str);
int					ft_check_dup(t_stack *a);
int					ft_check_sorted(t_stack *a);
int					ft_lstsize(t_stack *a);
void				ft_error(void);
void				ft_free(t_stack **lst);
void				ft_sort_3(t_stack **a);
void				ft_freestr(char **tmp);
void				ft_add_back(t_stack **a, t_stack *new);
void				ft_ra(t_stack **a, int j);
void				ft_rb(t_stack **b, int j);
void				ft_rr(t_stack **a, t_stack **b, int j);
void				ft_pa(t_stack **a, t_stack **b, int j);
void				ft_pb(t_stack **a, t_stack **b, int j);
void				ft_sa(t_stack **a, int j);
void				ft_sb(t_stack **b, int j);
void				ft_ss(t_stack **a, t_stack **b, int j);
void				ft_rra(t_stack **a, int j);
void				ft_rrb(t_stack **b, int j);
void				ft_rrr(t_stack **a, t_stack **b, int j);
void				current_index(t_stack *a);
void				set_cheapest(t_stack *a);
void				init_node_a(t_stack *a, t_stack *b);
void				init_node_b(t_stack *a, t_stack *b);
void				ft_sort(t_stack **a, t_stack **b);
void				rotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);
void				rev_rotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);
void				case_of_rarrb(t_stack **a, t_stack **b,
						t_stack *cheapest_node);
void				case_of_rrarb(t_stack **a, t_stack **b,
						t_stack *cheapest_node);
void				prep_for_push_a(t_stack **a, t_stack *top_node);
void				prep_for_push_b(t_stack **b, t_stack *top_node);
char				**ft_split(const char *s, char c);
char				*ft_strdup(char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
t_stack				*ft_lstlast(t_stack *a);
t_stack				*ft_lstnew(int content);
t_stack				*init_stack(int ac, char **av);
t_stack				*get_cheapest(t_stack *a);
t_stack				*ft_min(t_stack *a);
t_stack				*ft_max(t_stack *a);

// remove this after
void				print_stack(t_stack *stack);

#endif