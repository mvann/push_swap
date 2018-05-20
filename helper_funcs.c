/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:47:33 by mvann             #+#    #+#             */
/*   Updated: 2018/05/19 17:47:09 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_valid(char *s)
{
	int		i
	long	int_max;
	long	long_form;

	int_max = 2147483647
	long_form = ft_atol(av[i]);

	i = 0;
	while (i < ft_strlen(s))
	{
		if (!(i == 0 && (s[i] == '+' || s[i] == '-')))
		if (s[i]
	}
	if(ft_strlen(s) > 10 ||
	long_form > int_max || long_form < (int_max + 1) * -1)
}

void	error()
{
	ft_printf("Error\n");
	exit();
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
