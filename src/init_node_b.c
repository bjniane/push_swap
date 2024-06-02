/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 02:14:20 by bjniane           #+#    #+#             */
/*   Updated: 2024/06/02 16:04:52 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack *a, t_stack *b)
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

void	init_node_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}