/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:49:23 by bjniane           #+#    #+#             */
/*   Updated: 2024/06/02 16:05:39 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a, int j)
{
	t_stack	*last_node;

	if (!*a || !((*a)->next))
		return ;
	last_node = ft_lstlast(*a);
	last_node->next = *a;
	*a = (*a)->next;
	last_node->next->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int j)
{
	t_stack	*last_node;

	if (!*b || !((*b)->next))
		return ;
	last_node = ft_lstlast(*b);
	last_node->next = *b;
	*b = (*b)->next;
	last_node->next->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b, int j)
{
	ft_ra(a, 1);
	ft_rb(b, 1);
	if (j == 0)
		write(1, "rr\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "pb\n", 3);
}
void	ft_sa(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b, int j)
{
	ft_sa(a, 1);
	ft_sb(b, 1);
	if (j == 0)
		write(1, "ss\n", 3);
}
void	ft_rra(t_stack **a, int j)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*a || !((*a)->next))
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	if (j == 0)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int j)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*b || !((*b)->next))
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	if (j == 0)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	ft_rra(a, 1);
	ft_rrb(b, 1);
	if (j == 0)
		write(1, "rrr\n", 4);
	;
}