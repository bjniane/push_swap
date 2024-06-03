/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utilis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:17:37 by bjniane           #+#    #+#             */
/*   Updated: 2024/06/02 16:20:23 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

void	ft_add_back(t_stack **a, t_stack *new)
{
	t_stack	*last;

	if (*a == NULL)
	{
		*a = new;
		return ;
	}
	last = ft_lstlast(*a);
	last->next = new;
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

t_stack	*ft_min(t_stack *a)
{
	t_stack	*min_node;

	min_node = a;
	while (a)
	{
		if (a->data < min_node->data)
			min_node = a;
		a = a->next;
	}
	return (min_node);
}
