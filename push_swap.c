/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:53:38 by mvann             #+#    #+#             */
/*   Updated: 2018/06/21 14:11:09 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		base_cases(t_env *env, int n)
{
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
	return (0);
}

int		sort(t_env *env, int n)
{
	int pivot;
	int	current_num;
	int	i;
	int	count;

	if (base_cases(env, n))
		return (1);
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
	return (1);
}

int		main(int ac, char **av)
{
	t_env	env;

	ac--;
	av++;
	env.p_a = parse_list(ac, av);
	env.command_queue = (int *)ft_memalloc((sizeof(int)) * (COMMANDS_LEN + 1));
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
