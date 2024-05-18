/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:25:00 by bjniane           #+#    #+#             */
/*   Updated: 2024/05/18 09:48:40 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_b_till_3(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	while (ft_lstsize(*a) > 3 && !ft_check_sorted(*a))
	{
		tmp = *a;
	}
}

t_stack	*ft_sort_b(t_stack **a)
{
	t_stack *b;

	b = NULL;
	if (ft_lstsize(*a) > 3)
		ft_pb(a, &b, 0);
	if (ft_lstsize(*a) > 3)
		ft_pb(a, &b, 0);
	if (ft_lstsize(*a) > 3 && !ft_check_sorted(*a))
		ft_sort_b_till_3(a, &b);
	if (!ft_check_sorted(a))
		ft_sort_3(a);
	return (b);
}