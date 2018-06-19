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

void	sort_a()
{
	int i;

	i = 0;
	while (i < n)
	{
		if (ft_lstat(i, env->p_a) < );
		i++;
	}
}

void	sort_b()
{

}

void sort(t_env *env, int n, int side)
{

	sort(n / 2 + n % 2, !side);
	sort(n / 2, 0);
}

int	main(int ac, char **av)
{
	t_env	env;

	ac--;
	av++;
	env.p_a = parse_list(ac, av);

	sort_a(&env, ac, 0);

	print_int_list(env.p_a);

	return (0);
}
