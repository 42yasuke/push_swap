/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_r_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:48:04 by jralph            #+#    #+#             */
/*   Updated: 2022/12/28 11:19:23 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		stack_push(a, stack_pop(b), index);
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
	ft_set_pos(a);
	ft_set_pos(b);
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

t_node	*ft_node_max(t_stack *pile, int max)
{
	t_node	*node_max;
	t_node	*tmp;

	tmp = pile->begin->prev;
	node_max = pile->begin;
	if (max)
	{
		while (tmp != pile->begin)
		{
			if (tmp->data > node_max->data)
				node_max = tmp;
			tmp = tmp->prev;
		}
	}
	else
	{
		while (tmp != pile->begin)
		{
			if (tmp->data < node_max->data)
				node_max = tmp;
			tmp = tmp->prev;
		}
	}
	return (node_max);
}

int	ft_nbig_pos(t_stack *pile, t_node *node_max)
{
	t_node	*tmp;
	t_node	*node_sup;
	int		nbr;

	tmp = pile->begin;
	node_sup = ft_node_max(pile, 1);
	nbr = stack_size(pile);
	while (nbr--)
	{
		if (tmp->data >= node_max->data && tmp->data <= node_sup->data)
			node_sup = tmp;
		tmp = tmp->prev;
	}
	return (node_sup->pos);
}
