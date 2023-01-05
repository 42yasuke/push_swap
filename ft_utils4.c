/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:44:56 by jralph            #+#    #+#             */
/*   Updated: 2023/01/04 11:35:16 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_remote(t_stack *pileA, t_stack *pileb, t_node *node_opti)
{
	int	nbr;

	nbr = node_opti->pos;
	if ((float)stack_size(pileb) / (float)2 > (float)nbr)
		while (nbr--)
			ft_rotate_manager(NULL, pileb, "rb\n", 1);
	else
	{
		nbr = stack_size(pileb) - nbr;
		while (nbr--)
			ft_rotate_manager(NULL, pileb, "rrb\n", 1);
	}
	ft_five_loop(pileA, pileb);
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
	if ((node_max)->data > node_sup->data)
		return (ft_node_max(pile, 0)->pos);
	nbr = stack_size(pile);
	while (nbr--)
	{
		if (tmp->data >= node_max->data && tmp->data <= node_sup->data)
			node_sup = tmp;
		tmp = tmp->prev;
	}
	return (node_sup->pos);
}

t_node	*ft_find_highest(t_stack *pileA)
{
	t_node	*tmp;
	int		len;
	int		i;

	len = (ft_node_max(pileA, 1))->index + 1;
	i = len;
	tmp = pileA->begin;
	while (i--)
	{
		if (tmp->index < len - 3)
			return (tmp);
		tmp = tmp->prev;
	}
	return (NULL);
}

t_node	*ft_find_lowest(t_stack *pileA)
{
	t_node	*tmp;
	int		len ;
	int		i;

	len = (ft_node_max(pileA, 1))->index + 1;
	i = stack_size(pileA);
	tmp = pileA->end;
	while (i--)
	{
		if (tmp->index < len - 3)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
