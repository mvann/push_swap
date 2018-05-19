/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 12:23:18 by mvann             #+#    #+#             */
/*   Updated: 2018/05/19 13:20:00 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_two(t_list **a, t_list **b)
{
	int result;

	result = rotate(a) && rotate(b);
	return (result);
}

int	rotate(t_list **head)
{
	t_list *tmp;

	if (!head || !(*head) || !(*head)->next)
		return (0);
	tmp = (*head)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	tmp = (*head)->next;
	(*head)->next = NULL;
	(*head) = tmp;
	return (1);
}

int	derotate_two(t_list **a, t_list **b)
{
	int result;

	result = derotate(a) && derotate(b);
	return (result);
}

int	derotate(t_list **head)
{
	t_list *tmp;

	if (!head || !(*head) || !(*head)->next)
		return (0);
	tmp = (*head);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *head;
	*head = tmp->next;
	tmp->next = NULL;
	return (1);
}
