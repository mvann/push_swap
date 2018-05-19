/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:11:26 by mvann             #+#    #+#             */
/*   Updated: 2018/05/19 13:04:51 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_two(t_list **a, t_list **b)
{
	int result;

	result = swap(a) && swap(b);
	return (result);
}

int	swap(t_list **p_head_adr)
{
	t_list	*tmp;

	if (!p_head_adr)
		return (0);
	tmp = *p_head_adr;
	if (!tmp || !tmp->next)
		return (0);
	*p_head_adr = tmp->next;
	tmp->next = (*p_head_adr)->next;
	(*p_head_adr)->next = tmp;
	return (1);
}
