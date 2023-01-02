/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:35:07 by jralph            #+#    #+#             */
/*   Updated: 2023/01/02 11:07:22 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbr_opti(int a, int b, t_stack *pileA, t_stack *pileb)
{
	int		nbra;
	int		nbrb;

	nbra = a;
	nbrb = b;
	if ((float)nbra > (float)stack_size(pileA) / (float)2)
		nbra = stack_size(pileA) - nbra;
	if ((float)nbrb > (float)stack_size(pileb) / (float)2)
		nbrb = stack_size(pileb) - nbrb;
	return (nbra + nbrb);
}

int	ft_nbr_rr(t_stack *pileA, t_stack *pileb, t_node *node_opti)
{
	int	ra;
	int	rb;
	int	nbr_pos;

	ra = 0;
	rb = 0;
	nbr_pos = ft_nbig_pos(pileA, node_opti);
	if ((float)nbr_pos < (float)stack_size(pileA) / (float)2)
	{
		while (nbr_pos--)
			ra++;
	}
	nbr_pos = node_opti->pos;
	if ((float)nbr_pos < (float)stack_size(pileb) / (float)2)
	{
		while (nbr_pos--)
			rb++;
	}
	if (ra && rb)
	{
		if (ra < rb)
			return (ra);
		return (rb);
	}
	return (0);
}

static void	ft_suite(int nbr_pos, t_stack *pileb, int *rrb)
{
	if ((float)nbr_pos >= (float)stack_size(pileb) / (float)2)
	{
		nbr_pos = stack_size(pileb) - nbr_pos;
		while (nbr_pos--)
			(*rrb)++;
	}
}

int	ft_nbr_rrr(t_stack *pileA, t_stack *pileb, t_node *node_opti)
{
	int	rra;
	int	rrb;
	int	nbr_pos;

	rra = 0;
	rrb = 0;
	nbr_pos = ft_nbig_pos(pileA, node_opti);
	if ((float)nbr_pos >= (float)stack_size(pileA) / (float)2)
	{
		nbr_pos = stack_size(pileA) - nbr_pos;
		while (nbr_pos--)
			rra++;
	}
	nbr_pos = node_opti->pos;
	ft_suite(nbr_pos, pileb, &rrb);
	if (rra && rrb)
	{
		if (rra < rrb)
			return (rra);
		return (rrb);
	}
	return (0);
}
