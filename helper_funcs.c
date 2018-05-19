/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:47:33 by mvann             #+#    #+#             */
/*   Updated: 2018/05/19 16:47:20 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error()
{
	ft_printf("Error\n");
	exit();
}

int		sorted(t_list *l)
{
	int n;

	if (!l)
		return (1);
	n = *(int*)(l->content);
	while (l->next)
	{
		if (*(int*)l->next->content < n)
			return (0);
		n = *(int*)l->next->content;
		l = l->next;
	}
	return (1);
}
