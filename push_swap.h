/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:56:32 by mvann             #+#    #+#             */
/*   Updated: 2018/05/20 15:56:22 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct	s_env
{
	t_list		*p_a;
	t_list		*p_b;
}				t_env;

int				swap(t_list **p_head_adr);
int				swap_two(t_list **a, t_list **b);

int				rotate_two(t_list **a, t_list **b);
int				rotate(t_list **head);
int				derotate_two(t_list **a, t_list **b);
int				derotate(t_list **head);

int				push(t_list **l1, t_list **l2);
t_list			*pop(t_list **l);

int				is_valid(char *s);
void			error();
int				sorted(t_list *l);
long			ft_atol(const char *str);
void			print_int_list(t_list *l);

t_list			*parse_list(int ac, char **av);

#endif
