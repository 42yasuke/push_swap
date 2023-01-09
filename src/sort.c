/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:06:49 by jralph            #+#    #+#             */
/*   Updated: 2023/01/04 11:37:14 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sort(t_stack *pile)
{
	t_node	*tmp;
	int		nbr;

	tmp = pile->begin;
	nbr = tmp->data;
	while (tmp->prev != pile->begin)
	{
		if (nbr > tmp->prev->data)
			return (0);
		nbr = tmp->prev->data;
		tmp = tmp->prev;
	}
	return (1);
}

void	ft_sort_after_push(t_stack *pileA)
{
	int	nbr;

	nbr = (ft_node_max(pileA, 0))->pos;
	if ((float)stack_size(pileA) / (float)2 > (float)nbr)
		while (nbr--)
			ft_rotate_manager(pileA, NULL, "ra\n", 1);
	else
	{
		nbr = stack_size(pileA) - nbr;
		while (nbr--)
			ft_rotate_manager(pileA, NULL, "rra\n", 1);
	}
}
