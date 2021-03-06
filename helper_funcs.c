/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:47:33 by mvann             #+#    #+#             */
/*   Updated: 2018/06/21 14:05:32 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_valid(char *s)
{
	int		i;
	long	int_max;
	long	long_form;

	int_max = 2147483647;
	long_form = ft_atol(s);
	i = 0;
	while (i < (int)ft_strlen(s))
	{
		if (!ft_isdigit(s[i]))
			if (i > 0 || (s[i] != '+' && s[i] != '-'))
				return (0);
		i++;
	}
	if (ft_strlen(s) > 11 ||
	long_form > int_max || long_form < (int_max + 1) * -1)
		return (0);
	return (1);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int		section_sorted(t_list *l, int n)
{
	int i;
	int tmp;

	i = 0;
	tmp = *(int*)(l->content);
	while (i < n - 1)
	{
		if (*(int*)l->next->content < tmp)
			return (0);
		tmp = *(int*)l->next->content;
		l = l->next;
	}
	return (1);
}

int		sorted(t_list *l)
{
	int n;

	if (!l)
		return (1);
	n = *(int*)(l->content);
	while (l->next)
	{
		if (*(int*)l->next->content < n)
			return (0);
		n = *(int*)l->next->content;
		l = l->next;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	unsigned long	sum;
	int				i;
	int				negative;
	unsigned long	long_max;

	long_max = 9223372036854775807;
	i = 0;
	sum = 0;
	negative = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		negative = str[i++] == '-';
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum *= 10;
		sum += str[i] - '0';
		if (!negative && sum > long_max)
			return (-1);
		else if (negative && sum > long_max + 1)
			return (0);
		i++;
	}
	return ((long)sum * (negative ? -1 : 1));
}
