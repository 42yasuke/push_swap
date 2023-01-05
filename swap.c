/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:13:44 by jralph            #+#    #+#             */
/*   Updated: 2023/01/04 11:37:58 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *pile)
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
	}
}

void	ft_swap_manager(t_stack *pileA, t_stack *pileb, char *str, int print)
{
	if (ft_strlen(str) == 3)
	{
		if (str[1] != 's')
		{
			if (pileA)
				ft_swap(pileA);
			else
				ft_swap(pileb);
		}
		else
		{
			ft_swap(pileA);
			ft_swap(pileb);
		}
		ft_set_pos(pileA);
		ft_set_pos(pileb);
		if (print)
			write(1, str, ft_strlen(str));
	}
}
