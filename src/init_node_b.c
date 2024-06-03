/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 02:14:20 by bjniane           #+#    #+#             */
/*   Updated: 2024/06/03 14:40:13 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	target_of_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_target;

	while (b)
	{
		best_target = LONG_MAX;
		target_node = NULL;
		current_a = a;
		while (current_a)
		{
			if (current_a->data > b->data && current_a->data < best_target)
			{
				best_target = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_target == LONG_MAX)
			b->target = ft_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

static void	cost_of_b(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = len_b - (b->index);
		if (b->target->above_median)
			b->push_cost += b->target->index;
		else
			b->push_cost += len_a - (b->target->index);
		b = b->next;
	}
}

void	set_cheapest_b(t_stack *b)
{
	long	cheapesst_value;
	t_stack	*cheapest_node;

	if (!b)
		return ;
	cheapesst_value = LONG_MAX;
	cheapest_node = NULL;
	while (b)
	{
		if (b->push_cost < cheapesst_value)
		{
			cheapesst_value = b->push_cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_node_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	target_of_b(a, b);
	cost_of_b(a, b);
	set_cheapest_b(b);
}
