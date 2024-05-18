/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:11:18 by bjniane           #+#    #+#             */
/*   Updated: 2024/05/18 09:11:47 by bjniane          ###   ########.fr       */
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
	int		j;
	int		k;

	i = 1;
	a = NULL;
	if (ac < 2)
		ft_error();
	while (i < ac)
	{
		k = 0;
		if (ac == 2)
			tmp = ft_split(av[1], ' ');
		else
			tmp = ft_split(av[i], ' ');
		while (tmp[k])
		{
			j = ft_atoi(tmp[k]);
			ft_add_back(&a, ft_lstnew(j));
			k++;
		}
		ft_freestr(tmp);
		i++;
	}
	return (a);
}

// int	main(int ac, char **av)
// {
// 	t_stack *a;
// 	t_stack *b;

// 	a = NULL;
// 	b = NULL;
// 	a = init_stack(ac, av);
// 	if (!a || ft_check_dup(a))
// 	{
// 		ft_free(&a);
// 		ft_error();
// 	}
// 	if (!ft_check_sorted(a))
// 	{
// 		if (ft_lstsize(a) == 2)
// 			ft_sa(&a, 0);
// 		else if (ft_lstsize(a) == 3)
// 			ft_sort_3(&a);
// 		// else
// 		// {
// 		// 	ft_pb(a, b, 0);
// 		// 	ft_pb(a, b, 0);
// 		// 	ft_sort_b(&a, &b);
// 		// 	ft_sort_3(&a);
// 		// 	ft_sort_a(&a, &b);
// 		// }
// 	}
// 	ft_free(&a);
// }

void print_stack(t_stack *stack) {
    while (stack) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_stack	*a = NULL;
	//t_stack *b = NULL;;
	
	ft_add_back(&a, ft_lstnew(1));
	ft_add_back(&a, ft_lstnew(2));
	ft_add_back(&a, ft_lstnew(3));

	// ft_add_back(&b, ft_lstnew(6));
	// ft_add_back(&b, ft_lstnew(7));
	// ft_add_back(&b, ft_lstnew(8));
	
	printf("stack A:\n");
	print_stack(a);
	// printf("stack B:\n");
	// print_stack(b);
	
	ft_ra(&a, 0);
	printf("after ra\n");
	printf("stack A:\n");
	print_stack(a);
}

// int main(int argc, char **argv) {
//     // Call init_stack function
//     t_stack *stack = init_stack(argc, argv);

//     // Print the elements of the stack (assuming some print function exists)
//     printf("Stack: ");
//     while (stack != NULL) {
//         printf("%d ", stack->data);
//         stack = stack->next;
//     }
//     printf("\n");

//     return (0);
// }