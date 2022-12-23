/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:11:36 by jralph            #+#    #+#             */
/*   Updated: 2022/12/23 17:02:51 by jralph           ###   ########.fr       */
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

static void	ft_three_sort(t_stack *pile)
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

static void	ft_five_sort(t_stack *pileA)
{
	t_stack	*pileB;

	pileB = malloc(sizeof(*pileB));
	if (!pileB)
		return ;
	stack_initial(pileB);
	while(stack_size(pileA) != 3)
		ft_push(pileA, pileB, 0);
	ft_three_sort(pileA);
	while (pileB->begin)
	{
		if (pileB->begin->data > ft_data_max(pileA, 1))
		{
			ft_push(pileA, pileB, 1);
			ft_rotate(pileA, "ra\n");
		}
		else
		{
			if (stack_size(pileA)/2 < ft_nbig_pos(pileA, pileB->begin->data))/*on doit corriger*/
				while (pileA->begin)
		}
	}
}

void	ft_sort(t_stack *pile)
{
	int	size;

	size = stack_size(pile);
	if (size > 1 && size <= 3)
		ft_three_sort(pile);
	else if (size > 3 && size <= 5)
		ft_five_sort(pile);
	/*else if (size > 5 && size <= 100)
		ft_medium_sort(pile);
	else if (size > 100)
		ft_big_sort(pile);*/
}
