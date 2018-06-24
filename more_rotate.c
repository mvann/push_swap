/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 08:51:42 by mvann             #+#    #+#             */
/*   Updated: 2018/06/23 17:31:43 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rotate_a(t_env *env)
{
	rotate(&(env->p_a));
	ft_printf("ra\n");
	return (0);
}

void	rotate_b(t_env *env)
{
	rotate(&(env->p_b));
	ft_printf("rb\n");
}

int		rotate_both(t_env *env)
{
	rotate_two(&(env->p_a), &(env->p_b));
	ft_printf("rr\n");
	return (0);
}

int		derotate_a(t_env *env)
{
	derotate(&(env->p_a));
	ft_printf("rra\n");
	return (0);
}
