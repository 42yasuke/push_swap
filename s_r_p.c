/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_r_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:48:04 by jralph            #+#    #+#             */
/*   Updated: 2022/12/23 14:07:30 by jralph           ###   ########.fr       */
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
	ft_set_pos(pile);
}

void	ft_push(t_stack *a, t_stack *b, int is_pa)
{
	int	index;

	if (is_pa)
	{
		if (!b->begin)
			return ;
		index = b->begin->index;
		stack_push(a, stack_pop(b),index);
		write (1, "pa\n", 3);
	}
	else
	{
		if (!a->begin)
			return ;
			index = a->begin->index;
		stack_push(b, stack_pop(a), index);
		write (1, "pb\n", 3);
	}
	ft_set_pos(pile);
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
	ft_set_pos(pile);
	write(1, str, ft_strlen(str));
}

int	ft_data_max(t_stack *pile, int max)
{
	t_node	*tmp_max;
	t_node	*tmp;

	tmp = pile->begin;
	tmp_max = tmp;
	if (max)
	{
		while (tmp->prev != pile->begin)
		{
			if (tmp->data > tmp_max->data)
				tmp_max = tmp;
			tmp = tmp->prev;
		}
	}
	else
	{
		while (tmp->prev != pile->begin)
		{
			if (tmp->data < tmp_max->data)
				tmp_max = tmp;
			tmp = tmp->prev;
		}
	}
	return (tmp_max->data);
}

t_node	*ft_nbig_pos(t_stack *pile, int data)
{
	t_node	*tmp;

	tmp = pile->begin;
	while (tmp->prev != pile->begin)
	{
		if (tmp->data > data)
			return (tmp);
		tmp = tmp->prev;
	}
	return (NULL);
}
