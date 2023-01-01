/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:35:07 by jralph            #+#    #+#             */
/*   Updated: 2023/01/01 01:02:35 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbr_opti(int a, int b, t_stack *pileA, t_stack *pileb) /*ne prend pas en copmte les rr et rrr*/
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
	if ((float)nbr_pos >= (float)stack_size(pileb) / (float)2)
	{
		nbr_pos = stack_size(pileb) - nbr_pos;
		while (nbr_pos--)
			rrb++;
	}
	if (rra && rrb)
	{
		if (rra < rrb)
			return (rra);
		return (rrb);
	}
	return (0);
}

void	ft_rotate_manager(t_stack *pileA, t_stack *pileb, char *str)
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
	write(1, str, ft_strlen(str));
}
