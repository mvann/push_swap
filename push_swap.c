/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:53:38 by mvann             #+#    #+#             */
/*   Updated: 2018/06/18 19:12:37 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_back(t_env *env, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		push(&(env->p_a), &(env->p_b));
		ft_printf("pa\n");
		rotate(&(env->p_a));
		ft_printf("ra\n");
		i++;
	}
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
			i++;
		env->command_queue[i] = command;
	}
}

int	base_cases(t_env *env, int n)
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
		if (*((int *)(ft_lstat(0, env->p_a)->content)) >
		*((int *)(ft_lstat(1, env->p_a)->content)))
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

int sort(t_env *env, int n)
{
	// ft_printf("\t\t___yo n:%i\n", n);
	int pivot;
	int	current_num;
	int	i;
	int	count;

	if (base_cases(env, n))
		return (1);
	pivot = get_mid(
		*((int *)(ft_lstat(0, env->p_a)->content)),
		*((int *)(ft_lstat((n - 1) / 2, env->p_a)->content)),
		*((int *)(ft_lstat(n - 1, env->p_a)->content))
	);

	// ft_printf("\t\tpivot:%i\n", pivot);
	count = 0;
	i = 0;
	while (i < n)
	{
		current_num = *((int *)(ft_lstat(0, env->p_a)->content));
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
	get_back(env, count);
	add_command(env, n - count);
	add_command(env, count);
	return (1);
}

int	main(int ac, char **av)
{
	t_env	env;

	ac--;
	av++;
	env.p_a = parse_list(ac, av);
	env.command_queue = (int *)ft_memalloc((sizeof (int *)) * 2000);

	// print_int_list(env.p_a);
	add_command(&env, ac);
	while (!(sorted(env.p_a) && env.p_b == NULL))
	{
	// for (int i = 0; i < 40; i++){
		sort(&env, env.command_queue[env.command_i]);
		env.command_i++;
		// print_int_list(env.p_a);
	}
	// print_int_list(env.p_a);

	return (0);
}
