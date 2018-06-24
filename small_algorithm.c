/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:58:37 by mvann             #+#    #+#             */
/*   Updated: 2018/06/23 17:56:38 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_reversed_three(t_env *env)
{
	int a;
	int b;
	int c;

	a = int_in_lst_at(env->p_a, 0);
	b = int_in_lst_at(env->p_a, 1);
	c = int_in_lst_at(env->p_a, 2);
	return ((a > b && b > c) || (b > c && c > a) || (c > a && a > b));
}

void	sort_three(t_env *env)
{
	int a;
	int b;
	int c;

	if (is_reversed_three(env))
	{
		swap(&(env->p_a));
		ft_printf("sa\n");
	}
	a = int_in_lst_at(env->p_a, 0);
	b = int_in_lst_at(env->p_a, 1);
	c = int_in_lst_at(env->p_a, 2);
	if (b > a && a > c)
		derotate_a(env);
	else if (a > c && c > b)
	{
		rotate(&(env->p_a));
		ft_printf("ra\n");
	}
}

void	push_min(t_env *env, int n, int min_i)
{
	if (min_i < n - min_i)
	{
		while (min_i--)
			rotate_a(env);
		push_b(env);
	}
	else
	{
		while ((n - (min_i++)))
			derotate_a(env);
		push_b(env);
	}
}

void	move_min(t_env *env, int n)
{
	int i;
	int min_i;

	min_i = 0;
	i = 1;
	while (i < n)
	{
		if (int_in_lst_at(env->p_a, i) < int_in_lst_at(env->p_a, min_i))
			min_i = i;
		i++;
	}
	push_min(env, n, min_i);
}

void	small_algorithm(t_env *env, int n)
{
	while (n > 3)
	{
		move_min(env, n);
		n--;
	}
	sort_three(env);
	while (env->p_b)
		push_a(env);
}
