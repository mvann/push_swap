/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:21:02 by mvann             #+#    #+#             */
/*   Updated: 2018/06/14 13:00:14 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push(t_list **l1, t_list **l2, int	len_l2)
{
	t_list *tmp;

	if (len_l2 < 1 || !l2 || !(tmp = pop(l2)))
		return (0);
	ft_lstadd(l1, tmp);
	return (1);
}

t_list	*pop(t_list **l)
{
	t_list *tmp;

	if (!l || !(*l))
		return (NULL);
	tmp = (*l);
	(*l) = (*l)->next;
	tmp->next = NULL;
	return (tmp);
}
