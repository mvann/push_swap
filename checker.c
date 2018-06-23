/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:40:53 by mvann             #+#    #+#             */
/*   Updated: 2018/06/21 16:27:35 by mvann            ###   ########.fr       */
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

void	run_command(t_env *env, int command)
{
	if (command == SA)
		swap(&(env->p_a));
	else if (command == SB)
		swap(&(env->p_b));
	else if (command == SS)
		swap_two(&(env->p_a), &(env->p_b));
	else if (command == PA)
		push(&(env->p_a), &(env->p_b));
	else if (command == PB)
		push(&(env->p_b), &(env->p_a));
	else if (command == RA)
		rotate(&(env->p_a));
	else if (command == RB)
		rotate(&(env->p_b));
	else if (command == RR)
		rotate_two(&(env->p_a), &(env->p_b));
	else if (command == RRA)
		derotate(&(env->p_a));
	else if (command == RRB)
		derotate(&(env->p_b));
	else if (command == RRR)
		derotate_two(&(env->p_a), &(env->p_b));
}

int		main(int ac, char **av)
{
	t_env	env;
	int		command;
	char	*str;

	str = NULL;
	ac--;
	av++;
	if (ac >= 1)
	{
		env.p_a = parse_list(ac, av);
		env.len_a = ac;
		env.len_b = 0;
		while (get_next_line(0, &str))
		{
			if (!(command = get_command_num(str)))
				error();
			run_command(&env, command);
			free(str);
		}
		if (sorted(env.p_a) && env.p_b == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
