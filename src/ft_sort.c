/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:25:00 by bjniane           #+#    #+#             */
/*   Updated: 2024/06/03 14:39:38 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both_a(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		rev_rotate_both_a(a, b, cheapest_node);
	else if (cheapest_node->above_median
		&& !(cheapest_node->target->above_median))
		case_of_rarrb_a(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& cheapest_node->target->above_median)
		case_of_rrarb_a(a, b, cheapest_node);
	prep_for_push_a(a, cheapest_node);
	prep_for_push_b(b, cheapest_node->target);
	ft_pb(a, b, 0);
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both_b(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		rev_rotate_both_b(a, b, cheapest_node);
	else if (cheapest_node->above_median
		&& !(cheapest_node->target->above_median))
		case_of_rrarb_b(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& cheapest_node->target->above_median)
		case_of_rrbra_b(a, b, cheapest_node);
	prep_for_push_b(b, cheapest_node);
	prep_for_push_a(a, cheapest_node->target);
	ft_pa(a, b, 0);
}

static void	min_on_top(t_stack **a)
{
	while ((*a)->data != ft_min(*a)->data)
	{
		if (ft_min(*a)->above_median)
			ft_ra(a, 0);
		else
			ft_rra(a, 0);
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int	len_a;

	ft_pb(a, b, 0);
	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !ft_check_sorted(*a))
		ft_pb(a, b, 0);
	while (len_a-- > 3 && !ft_check_sorted(*a))
	{
		init_node_a(*a, *b);
		move_a_to_b(a, b);
	}
	ft_sort_3(a);
	while (*b)
	{
		init_node_b(*a, *b);
		move_b_to_a(a, b);
	}
	min_on_top(a);
}
