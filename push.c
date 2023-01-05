/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:21:05 by jralph            #+#    #+#             */
/*   Updated: 2023/01/04 11:14:37 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *a, t_stack *b, int is_pa, int print)
{
	int	index;

	if (is_pa)
	{
		if (!b->begin)
			return ;
		index = b->begin->index;
		stack_push(a, stack_pop(b), index);
		if (print)
			write (1, "pa\n", 3);
	}
	else
	{
		if (!a->begin)
			return ;
		index = a->begin->index;
		stack_push(b, stack_pop(a), index);
		if (print)
			write (1, "pb\n", 3);
	}
	ft_set_pos(a);
	ft_set_pos(b);
}

void	ft_push_interval5(t_stack *pileA, t_stack *pileb)
{
	t_node	*node_top;
	t_node	*node_low;
	int		i;

	while (stack_size(pileA) != 3)
	{
		node_top = ft_find_highest(pileA);
		node_low = ft_find_lowest(pileA);
		if (!node_top)
			break ;
		i = node_top->pos;
		if ((float)i < (float)stack_size(pileA) / (float)2)
			while (i--)
				ft_rotate_manager(pileA, NULL, "ra\n", 1);
		else
		{
			i = node_low->pos;
			while (i--)
				ft_rotate_manager(pileA, NULL, "rra\n", 1);
		}
		ft_push(pileA, pileb, 0, 1);
		if ((float)pileb->begin->index < (float)((ft_node_max(pileA, 1))->index \
		+ 1) / (float)2)
			ft_rotate_manager(NULL, pileb, "rb\n", 1);
	}
}

t_node	*ft_push_opti(t_stack *pileA, t_stack *pileb)
{
	int		nbr_opti;
	int		nb;
	int		i;
	t_node	*tmp;
	t_node	*tmp_opti;

	nbr_opti = 1000;
	tmp = pileb->begin;
	tmp_opti = tmp;
	i = stack_size(pileb);
	while (i--)
	{
		nb = ft_nbr_opti(ft_nbig_pos(pileA, tmp), tmp->pos, pileA, pileb);
		if (nb < nbr_opti)
		{
			nbr_opti = nb;
			tmp_opti = tmp;
		}
		tmp = tmp->prev;
	}
	return (tmp_opti);
}
