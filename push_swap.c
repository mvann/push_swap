/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:53:38 by mvann             #+#    #+#             */
/*   Updated: 2018/06/20 20:24:54 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_in_lst_at(t_list *lst, int i)
{
	return (*((int *)(ft_lstat(i, lst)->content)));
}

int	get_median(t_list *lst, int n)
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
			{
				current_smallest = current;
			}
			j++;
		}
		smallest = current_smallest;
		i++;
	}
	return (current_smallest);
}

int	get_mid(int n1, int n2, int n3)
{
	if (n1 > n2)
	{
		if (n2 > n3)
			return n2;
		else if (n1 > n3)
			return n3;
		return n1;
	}
	if (n1 > n3)
		return n1;
	else if (n2 > n3)
		return n3;
	return n2;
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

int		get_back(t_env *env, int n)
{
	int i;
	int pivot;
	int	count;
	int current_num;
	int need_to_rot_a;

	count = 0;
	if (n <= 2)
	{
		i = 0;
		while (i < n)
		{
			push(&(env->p_a), &(env->p_b));
			ft_printf("pa\n");
			rotate(&(env->p_a));
			ft_printf("ra\n");
			i++;
		}
		add_command(env, n);
		return (1);
	}
	// pivot = get_mid(int_in_lst_at(env->p_b, 0),
	// 	int_in_lst_at(env->p_b, (n - 1) / 2), int_in_lst_at(env->p_b, n - 1));
	pivot = get_median(env->p_b, n);
	need_to_rot_a = 0;
	i = 0;
	while (i < n)
	{
		current_num = int_in_lst_at(env->p_b, 0);
		if (current_num < pivot)
		{
			if (need_to_rot_a)
			{
				rotate(&(env->p_a));
				ft_printf("ra\n");
			}
			push(&(env->p_a), &(env->p_b));
			ft_printf("pa\n");
			need_to_rot_a = 1;
			count++;
		}
		else
		{
			if (need_to_rot_a)
			{
				rotate_two(&(env->p_a), &(env->p_b));
				ft_printf("rr\n");
				need_to_rot_a = 0;
			}
			else
			{
				rotate(&(env->p_b));
				ft_printf("rb\n");
			}
		}
		i++;
	}
	if (need_to_rot_a)
	{
		rotate(&(env->p_a));
		ft_printf("ra\n");
		need_to_rot_a = 0;
	}
	add_command(env, count);
	get_back(env, n - count);
	return (1);
}

// void	get_back(t_env *env, int n)
// {
// 	int i;
//
// 	i = 0;
// 	while(i < n)
// 	{
// 		push(&(env->p_a), &(env->p_b));
// 		ft_printf("pa\n");
// 		rotate(&(env->p_a));
// 		ft_printf("ra\n");
// 		i++;
// 	}
// }

int	base_cases(t_env *env, int n)
{
	// int i;

	if (n == 0)
		return (1);
	else if (n == 1)
	{
		rotate(&(env->p_a));
		ft_printf("ra\n");
		add_command(env, 1);
		return (1);
	}
	else if (n == 2)
	{
		if (int_in_lst_at(env->p_a, 0) > int_in_lst_at(env->p_a, 1))
		{
			swap(&(env->p_a));
			ft_printf("sa\n");
		}
		rotate(&(env->p_a));
		ft_printf("ra\n");
		rotate(&(env->p_a));
		ft_printf("ra\n");
		add_command(env, 1);
		add_command(env, 1);
		return (1);
	}
	// else if (section_sorted(env->p_a, n))
	// {
	// 	i = 0;
	// 	while (i < n)
	// 	{
	// 		rotate(&(env->p_a));
	// 		ft_printf("ra\n");
	// 		i++;
	// 	}
	// 	add_command(env, n);
	// }
	return (0);
}

int sort(t_env *env, int n)
{
	int pivot;
	int	current_num;
	int	i;
	int	count;

	if (base_cases(env, n))
		return (1);
	// pivot = get_mid(int_in_lst_at(env->p_a, 0),
	// 	int_in_lst_at(env->p_a, (n - 1) / 2), int_in_lst_at(env->p_a, n - 1));
	pivot = get_median(env->p_a, n);
	count = 0;
	i = 0;
	while (i < n)
	{
		current_num = int_in_lst_at(env->p_a, 0);
		if (current_num > pivot)
		{
			push(&(env->p_b), &(env->p_a));
			ft_printf("pb\n");
			count++;
		}
		else
		{
			rotate(&(env->p_a));
			ft_printf("ra\n");
		}
		i++;
	}
	add_command(env, n - count);
	get_back(env, count);
	// add_command(env, count);
	return (1);
}

int	main(int ac, char **av)
{
	t_env	env;

	ac--;
	av++;
	env.p_a = parse_list(ac, av);
	// ft_printf("MEDIAN:%i\n", get_median(env.p_a, ac));
	env.command_queue = (int *)ft_memalloc((sizeof (int)) * (COMMANDS_LEN + 1));
	add_command(&env, ac);
	while (!(sorted(env.p_a) && env.p_b == NULL))
	{
		sort(&env, env.command_queue[env.command_i]);
		env.command_queue[env.command_i] = 0;
		env.command_i++;
		env.command_i = env.command_i >= COMMANDS_LEN ? 0 : env.command_i;
	}
	return (0);
}
