/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:39 by bjniane           #+#    #+#             */
/*   Updated: 2024/06/03 14:39:55 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both_b(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
		ft_rr(a, b, 0);
}

void	rev_rotate_both_b(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
		ft_rrr(a, b, 0);
}

void	case_of_rrarb_b(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*b) != cheapest_node || (*a) != cheapest_node->target)
	{
		if ((*b) != cheapest_node)
			ft_rb(b, 0);
		if ((*a) != cheapest_node->target)
			ft_rra(a, 0);
	}
}

void	case_of_rrbra_b(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*b) != cheapest_node || (*a) != cheapest_node->target)
	{
		if ((*b) != cheapest_node)
			ft_rrb(b, 0);
		if ((*a) != cheapest_node->target)
			ft_ra(a, 0);
	}
}
