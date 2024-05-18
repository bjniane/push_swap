/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:57:46 by bjniane           #+#    #+#             */
/*   Updated: 2024/05/16 21:08:28 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

size_t				ft_strlen(const char *str);
int					main(int ac, char **av);
int					ft_atoi(const char *str);
int					ft_check_dup(t_stack *a);
int					ft_check_sorted(t_stack *a);
int					ft_lstsize(t_stack *a);
int					ft_min(t_stack *a);
int					ft_max(t_stack *a);
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
char				**ft_split(const char *s, char c);
char				*ft_strdup(char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
t_stack				*ft_lstlast(t_stack *a);
t_stack				*ft_lstnew(int content);
t_stack				*init_stack(int ac, char **av);

#endif