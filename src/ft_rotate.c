/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 02:01:09 by bjniane           #+#    #+#             */
/*   Updated: 2024/06/02 16:03:06 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		ft_rr(a, b, 0);
	// current_index(*a);
	// current_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		ft_rrr(a, b, 0);
	// current_index(*a);
	// current_index(*b);
}

void	case_of_rarrb(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*a) != cheapest_node || (*b) != cheapest_node->target)
	{
		if ((*a) != cheapest_node)
			ft_ra(a, 0);
		if ((*b) != cheapest_node->target)
			ft_rrb(b, 0);
	}
	// current_index(*a);
	// current_index(*b);
}

void	case_of_rrarb(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*a) != cheapest_node || (*b) != cheapest_node->target)
	{
		if ((*a) != cheapest_node)
			ft_rra(a, 0);
		if ((*b) != cheapest_node->target)
			ft_rb(b, 0);
	}
	// current_index(*a);
	// current_index(*b);
}
