/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:20:00 by mvann             #+#    #+#             */
/*   Updated: 2018/05/20 15:46:30 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parse_list(int ac, char **av)
{
	int		i;
	t_list	*list;
	t_list	*tmp;
	int		*inter;

	list = NULL;
	i = 0;
	while (i < ac)
	{
		if (!is_valid(av[ac - i - 1]))
			error();
		inter = ft_memalloc(sizeof(int));
		*inter = ft_atoi(av[ac - i - 1]);
		tmp = ft_lstnew(inter, sizeof(int));
		tmp->next = list;
		list = tmp;
		i++;
	}
	return (list);
}
