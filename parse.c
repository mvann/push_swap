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

void	check_for_duplicates(t_list *l, int ac)
{
	int i;
	int j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (j < ac)
		{
			if (i != j && int_in_lst_at(l, i) == int_in_lst_at(l, j))
				error();
			j++;
		}
		i++;
	}
}

t_list	*parse_list(int ac, char **av)
{
	int		i;
	t_list	*list;
	t_list	*tmp;
	int		inter;

	list = NULL;
	i = 0;
	while (i < ac)
	{
		if (!is_valid(av[ac - i - 1]))
			error();
		inter = ft_atoi(av[ac - i - 1]);
		tmp = ft_lstnew(&inter, sizeof(int));
		tmp->next = list;
		list = tmp;
		i++;
	}
	check_for_duplicates(list, ac);
	return (list);
}
