/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:05:42 by jralph            #+#    #+#             */
/*   Updated: 2022/12/28 21:49:05 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_after_push(t_stack *pileA)
{
	int	nbr;

	nbr = (ft_node_max(pileA, 0))->pos;
	if ((float)stack_size(pileA) / (float)2 > (float)nbr)
		while (nbr--)
			ft_rotate(pileA, "ra\n");
	else
	{
		nbr = stack_size(pileA) - nbr;
		while (nbr--)
			ft_rotate(pileA, "rra\n");
	}
}

void	ft_five_loop(t_stack *pileA, t_stack *pileb)
{
	int	nbr;

	while (pileb->begin)
	{
		if (pileb->begin->data > (ft_node_max(pileA, 1))->data)
		{
			ft_sort_after_push(pileA);
			ft_push(pileA, pileb, 1);
			ft_rotate(pileA, "ra\n");
		}
		else
		{
			nbr = ft_nbig_pos(pileA, pileb->begin);
			if ((float)stack_size(pileA) / (float)2 > (float)nbr)
				while (nbr--)
					ft_rotate(pileA, "ra\n");
			else
			{
				nbr = stack_size(pileA) - nbr;
				while (nbr--)
					ft_rotate(pileA, "rra\n");
			}
			ft_push(pileA, pileb, 1);
		}
	}
}

t_node	*ft_find_highest(t_stack *pileA, int lim)
{
	t_node	*tmp;

	tmp = pileA->begin;
	while (tmp->prev != pileA->begin)
	{
		if (tmp->index < lim)
			return (tmp);
		tmp = tmp->prev;
	}
	return (pileA->begin);
}

t_node	*ft_find_lowest(t_stack *pileA, int lim)
{
	t_node	*tmp;

	tmp = pileA->end;
	while (tmp->next != pileA->end)
	{
		if (tmp->index < lim)
			return (tmp);
		tmp = tmp->next;
	}
	return (pileA->end);
}

void	ft_push_interval5(t_stack *pileA, t_stack *pileb, int i, int *count)
{
	t_node	*highest;
	t_node	*lowest;

	while ((*count) < i * 18 && stack_size(pileA) != 3)
	{
		highest = ft_find_highest(pileA, i * 18);
		lowest = ft_find_lowest(pileA, i * 18);
		if ((highest->index < i * 18) \
		&& (highest->pos < stack_size(pileA) - lowest->pos))
		{
			while (pileA->begin != highest)
				ft_rotate(pileA, "ra\n");
		}
		else if (lowest->index < i * 18)
		{
			while (pileA->begin != lowest)
				ft_rotate(pileA, "rra\n");
		}
		ft_push(pileA, pileb, 0);
		(*count)++;
	}
}
