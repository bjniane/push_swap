/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:11:18 by bjniane           #+#    #+#             */
/*   Updated: 2024/06/30 00:07:22 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freestr(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		k;

	i = 1;
	a = NULL;
	if (ac < 2)
		exit(0);
	while (i < ac)
	{
		k = 0;
		if (!check_error(av, 1, 0))
			ft_error();
		if (ac == 2)
			tmp = ft_split(av[1], ' ');
		else
			tmp = ft_split(av[i], ' ');
		while (tmp[k])
			ft_add_back(&a, ft_lstnew(ft_atoi(tmp[k++])));
		ft_freestr(tmp);
		i++;
	}
	return (a);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	a = init_stack(ac, av);
	if (!a || ft_check_dup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_check_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			ft_sa(&a, 0);
		else if (ft_lstsize(a) == 3)
			ft_sort_3(&a);
		else
			ft_sort(&a, &b);
	}
	ft_free(&a);
	ft_free(&b);
}
