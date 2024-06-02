/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:14:22 by bjniane           #+#    #+#             */
/*   Updated: 2024/06/02 16:04:44 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *a)
{
	int	i;
	int	median;

	i = 0;
	if (!a)
		return ;
	median = ft_lstsize(a) / 2;
	while (a)
	{
		a->index = i;
		if (i <= median)
			a->above_median = 1;
		else
			a->above_median = 0;
		a = a->next;
		i++;
	}
}

static void	target_of_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_target;

	while (a)
	{
		best_target = LONG_MIN;
		target_node = NULL;
		current_b = b;
		while (current_b)
		{
			if (current_b->data < a->data && current_b->data > best_target)
			{
				best_target = current_b->data;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (target_node == NULL)
			a->target = ft_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

static void	cost_of_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack *a)
{
	long	cheapesst_value;
	t_stack	*cheapest_node;

	if (!a)
		return ;
	cheapesst_value = LONG_MAX;
	cheapest_node = NULL;
	while (a)
	{
		if (a->push_cost < cheapesst_value)
		{
			cheapesst_value = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_node_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	target_of_a(a, b);
	cost_of_a(a, b);
	set_cheapest(a);
}