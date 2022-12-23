/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_r_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:48:04 by jralph            #+#    #+#             */
/*   Updated: 2022/12/23 09:51:54 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_r_p.h"

void	ft_swap(t_stack *pile, int is_stack_a)
{
	int		val;
	t_node	*tmp;

	val = 0;
	tmp = pile->begin;
	if (stack_size(pile) > 1)
	{
		val = tmp->data;
		tmp->data = tmp->prev->data;
		tmp->prev->data = val;
		if (is_stack_a)
			write (1, "sa\n", 3);
		else
			write (1, "sb\n", 3);
	}
}

void	ft_push(t_stack *a, t_stack *b, int is_pa)
{
	if (is_pa)
	{
		if (!b->begin)
			return ;
		stack_push(a, stack_pop(b));
		write (1, "pa\n", 3);
	}
	else
	{
		if (!a->begin)
			return ;
		stack_push(b, stack_pop(a));
		write (1, "pb\n", 3);
	}
}

void	ft_rotate(t_stack *pile, char *str)
{
	if (str[1] != 'r')
	{
		pile->begin = pile->begin->prev;
		pile->end = pile->end->prev;
	}
	else
	{
		pile->begin = pile->begin->next;
		pile->end = pile->end->next;
	}
	write(1, str, ft_strlen(str));
}
