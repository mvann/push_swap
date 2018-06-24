/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:53:38 by mvann             #+#    #+#             */
/*   Updated: 2018/06/23 17:56:47 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_back_helper(t_env *env, int n, int *count, int *need_to_rot_a)
{
	int i;
	int pivot;

	pivot = get_median(env->p_b, n);
	i = 0;
	while (i < n)
	{
		if (int_in_lst_at(env->p_b, 0) < pivot)
		{
			if (*need_to_rot_a)
				rotate_a(env);
			push_a(env);
			(*need_to_rot_a) = 1;
			(*count)++;
		}
		else
		{
			if (*need_to_rot_a)
				(*need_to_rot_a) = rotate_both(env);
			else
				rotate_b(env);
		}
		i++;
	}
}

int		get_back(t_env *env, int n)
{
	int i;
	int	count;
	int need_to_rot_a;

	count = 0;
	if (n <= 2)
	{
		i = 0;
		while (i < n)
		{
			push_a(env);
			rotate_a(env);
			i++;
		}
		add_command(env, n);
		return (1);
	}
	need_to_rot_a = 0;
	get_back_helper(env, n, &count, &need_to_rot_a);
	if (need_to_rot_a)
		need_to_rot_a = rotate_a(env);
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
		rotate_a(env);
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
		if (!sorted(env->p_a) || env->p_b)
		{
			rotate_a(env);
			rotate_a(env);
		}
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
			push_b(env);
			count++;
		}
		else
			rotate_a(env);
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
	if (ac < 8 && ac > 2 && !sorted(env.p_a))
		small_algorithm(&env, ac);
	else
	{
		env.command_queue =
			(int *)ft_memalloc((sizeof(int)) * (COMMANDS_LEN + 1));
		add_command(&env, ac);
		while (!(sorted(env.p_a) && env.p_b == NULL))
		{
			sort(&env, env.command_queue[env.command_i]);
			env.command_queue[env.command_i] = 0;
			env.command_i++;
			env.command_i = env.command_i >= COMMANDS_LEN ? 0 : env.command_i;
		}
	}
	return (0);
}
