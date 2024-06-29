/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:46:20 by bjniane           #+#    #+#             */
/*   Updated: 2024/06/30 00:11:09 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

static int	digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

static int	space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	check_error(char **av, int i, int j)
{
	while (av[i])
	{
		j = 0;
		while ((av[i][j] != '\0'))
		{
			if (sign(av[i][j]))
			{
				if (!digit(av[i][++j]))
					return (0);
			}
			else if (digit(av[i][j]))
			{
				j++;
				if (av[i][j] == '\0')
					break ;
				if (!digit(av[i][j]) && !space(av[i][j]))
					return (0);
			}
			else if (!digit(av[i][j]) && !space(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
