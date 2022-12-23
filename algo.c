/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:11:36 by jralph            #+#    #+#             */
/*   Updated: 2022/12/23 10:20:25 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static int	ft_is_sort(t_stack *pile)
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

void	ft_three_sort(t_stack *pile)
{
	t_node	*tmp_max;
	int		len;

	tmp_max = pile->begin;
	len = stack_size(pile);
	while (tmp_max->index != len - 1)
		tmp_max = tmp_max->prev;
	if (tmp_max == pile->begin)
	{
		ft_rotate(pile, "ra\n");
		if (!ft_is_sort(pile))
			return (ft_swap(pile, 1));
	}
	else if (tmp_max == pile->end && !ft_is_sort(pile))
		return (ft_swap(pile, 1));
	else if (!ft_is_sort(pile))
	{
		ft_rotate(pile, "rra\n");
		if (!ft_is_sort(pile))
			return (ft_swap(pile, 1));
	}
}

void	ft_sort(t_stack *pile)
{
	int	size;

	size = stack_size(pile);
	if (size > 1 && size <= 3)
		ft_three_sort(pile);
	/*else if (size > 3 && size <= 5)
		ft_five_sort(pile);
	else if (size > 5 && size <= 100)
		ft_medium_sort(pile);
	else if (size > 100)
		ft_big_sort(pile);*/
}
