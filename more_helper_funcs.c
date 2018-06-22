/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_helper_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:04:21 by mvann             #+#    #+#             */
/*   Updated: 2018/06/21 14:10:22 by mvann            ###   ########.fr       */
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

int		int_in_lst_at(t_list *lst, int i)
{
	return (*((int *)(ft_lstat(i, lst)->content)));
}

int		get_median(t_list *lst, int n)
{
	int i;
	int j;
	int smallest;
	int current;
	int current_smallest;

	smallest = -2147483648;
	current_smallest = smallest;
	i = 0;
	while (i < (n + 1) / 2)
	{
		j = 0;
		while (j < n)
		{
			current = int_in_lst_at(lst, j);
			if (current > smallest &&
			(current_smallest == smallest || current < current_smallest))
				current_smallest = current;
			j++;
		}
		smallest = current_smallest;
		i++;
	}
	return (current_smallest);
}

int		get_mid(int n1, int n2, int n3)
{
	if (n1 > n2)
	{
		if (n2 > n3)
			return (n2);
		else if (n1 > n3)
			return (n3);
		return (n1);
	}
	if (n1 > n3)
		return (n1);
	else if (n2 > n3)
		return (n3);
	return (n2);
}

void	add_command(t_env *env, int command)
{
	int i;

	if (command)
	{
		i = env->command_i;
		while (env->command_queue[i])
		{
			i++;
			if (i >= COMMANDS_LEN)
				i = 0;
		}
		env->command_queue[i] = command;
	}
}
