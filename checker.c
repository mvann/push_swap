/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:40:53 by mvann             #+#    #+#             */
/*   Updated: 2018/06/07 19:39:52 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_command_num(char *str)
{
	if (!ft_strcmp(str, "sa"))
		return (SA);
	else if (!ft_strcmp(str, "sb"))
		return (SB);
	else if (!ft_strcmp(str, "ss"))
		return (SS);
	else if (!ft_strcmp(str, "pa"))
		return (PA);
	else if (!ft_strcmp(str, "pb"))
		return (PB);
	else if (!ft_strcmp(str, "ra"))
		return (RA);
	else if (!ft_strcmp(str, "rb"))
		return (RB);
	else if (!ft_strcmp(str, "rr"))
		return (RR);
	else if (!ft_strcmp(str, "rra"))
		return (RRA);
	else if (!ft_strcmp(str, "rrb"))
		return (RRB);
	else if (!ft_strcmp(str, "rrr"))
		return (RRR);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	*env;
	int		command;

	env = (t_env *)ft_memalloc(sizeof (t_env));
	char *str;
	str = NULL;

	ac--;
	av++;
	env->p_a = parse_list(ac, av);
	while (get_next_line(1, &str))
	{
		if (!(command = get_command_num(str)))
			error();
		ft_printf("s:%s, i:%i,\n", str, command);
		// run_command(env, command);
	}
	return (0);
}
