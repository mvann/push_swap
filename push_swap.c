/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:53:38 by mvann             #+#    #+#             */
/*   Updated: 2018/05/19 14:09:47 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_int_list(t_list *l)
{
	while (l)
	{
		ft_printf("%i\n", *(int*)l->content);
		l = l->next;
	}
}

int	main()
{
	t_list *a;
	// t_list *b;
	// t_list *tmp;

	int intarr[4] = {1,2,3,4};
	a = ft_lstnew(intarr, sizeof(int));
	// ft_lstadd(&a, ft_lstnew(intarr + 1, sizeof(int)));
	// ft_lstadd(&a, ft_lstnew(intarr + 2, sizeof(int)));
	print_int_list(a);
	ft_printf("---\n");
	swap(&a);
	// derotate(&a);
	print_int_list(a);
	ft_printf("---\n");
	ft_printf("sorted: %i\n", sorted(NULL));
	// b = ft_lstnew(intarr, sizeof(int));
	// ft_lstadd(&b, ft_lstnew(intarr + 1, sizeof(int)));
	// ft_lstadd(&b, ft_lstnew(intarr + 2, sizeof(int)));


	return (0);
}
