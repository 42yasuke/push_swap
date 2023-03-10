/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:05:42 by jralph            #+#    #+#             */
/*   Updated: 2023/01/04 11:25:53 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_five_loop(t_stack *pileA, t_stack *pileb)
{
	int	nbr;

	if (pileb->begin->data > (ft_node_max(pileA, 1))->data)
	{
		ft_sort_after_push(pileA);
		ft_push(pileA, pileb, 1, 1);
		ft_rotate_manager(pileA, NULL, "ra\n", 1);
	}
	else
	{
		nbr = ft_nbig_pos(pileA, pileb->begin);
		if ((float)stack_size(pileA) / (float)2 > (float)nbr)
			while (nbr--)
				ft_rotate_manager(pileA, NULL, "ra\n", 1);
		else
		{
			nbr = stack_size(pileA) - nbr;
			while (nbr--)
				ft_rotate_manager(pileA, NULL, "rra\n", 1);
		}
		ft_push(pileA, pileb, 1, 1);
	}
}

void	ft_five_loop2(t_stack *pileA, t_stack *pileb)
{
	int		nbr;
	t_node	*node_opti;

	while (pileb->begin)
	{
		node_opti = ft_push_opti(pileA, pileb);
		nbr = ft_nbr_rr(pileA, pileb, node_opti);
		if (nbr)
			while (nbr--)
				ft_rotate_manager(pileA, pileb, "rr\n", 1);
		nbr = ft_nbr_rrr(pileA, pileb, node_opti);
		if (nbr)
			while (nbr--)
				ft_rotate_manager(pileA, pileb, "rrr\n", 1);
		ft_remote(pileA, pileb, node_opti);
	}
}
