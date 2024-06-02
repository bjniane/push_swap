/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_for_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:42:57 by bjniane           #+#    #+#             */
/*   Updated: 2024/06/02 16:05:18 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push_a(t_stack **a, t_stack *top_node)
{
	if ((*a)->above_median)
	{
		while (*a != top_node)
			ft_ra(a, 0);
	}
	else
	{
		while (*a != top_node)
			ft_rra(a, 0);
	}
}

void	prep_for_push_b(t_stack **b, t_stack *top_node)
{
	if ((*b)->above_median)
	{
		while (*b != top_node)
			ft_rb(b, 0);
	}
	else
	{
		while (*b != top_node)
			ft_rrb(b, 0);
	}
}
