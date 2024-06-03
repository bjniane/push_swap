/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:37:43 by bjniane           #+#    #+#             */
/*   Updated: 2024/06/02 16:21:09 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_max(t_stack *a)
{
	t_stack	*max_node;

	max_node = a;
	while (a)
	{
		if (a->data > max_node->data)
			max_node = a;
		a = a->next;
	}
	return (max_node);
}

void	ft_sort_3(t_stack **a)
{
	if (*a == ft_max(*a))
		ft_ra(a, 0);
	else if ((*a)->next == ft_max(*a))
		ft_rra(a, 0);
	if ((*a)->data > (*a)->next->data)
		ft_sa(a, 0);
}
