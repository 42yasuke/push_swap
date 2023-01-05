/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 01:00:53 by jralph            #+#    #+#             */
/*   Updated: 2023/01/04 11:09:53 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

void	ft_rotate_manager(t_stack *pileA, t_stack *pileb, char *str, int print)
{
	if (ft_strlen(str) == 3)
	{
		if (str[1] != 'r')
		{
			if (pileA)
				ft_rotate(pileA, "ra");
			else
				ft_rotate(pileb, "rb");
		}
		else
		{
			ft_rotate(pileA, "ra");
			ft_rotate(pileb, "rb");
		}
	}
	else
		ft_rotate_manager_else(pileA, pileb, str);
	ft_set_pos(pileA);
	ft_set_pos(pileb);
	if (print)
		write(1, str, ft_strlen(str));
}

void	ft_rotate_manager_else(t_stack *pileA, t_stack *pileb, char *str)
{
	if (str[2] != 'r')
	{
		if (pileA)
			ft_rotate(pileA, "rra");
		else
			ft_rotate(pileb, "rrb");
	}
	else
	{
		ft_rotate(pileA, "rra");
		ft_rotate(pileb, "rrb");
	}
}
