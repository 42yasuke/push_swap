/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:44:25 by jralph            #+#    #+#             */
/*   Updated: 2023/01/01 01:02:02 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_remote(t_stack *pileA, t_stack *pileb, t_node *node_opti)
{
	int	nbr;

	nbr = node_opti->pos;
	if ((float)stack_size(pileb) / (float)2 > (float)nbr)
		while (nbr--)
			ft_rotate_manager(NULL, pileb, "rb\n");
	else
	{
		nbr = stack_size(pileb) - nbr;
		while (nbr--)
			ft_rotate_manager(NULL, pileb, "rrb\n");
	}
	ft_five_loop(pileA, pileb);
}

/*void	ft_five_loop2(t_stack *pileA, t_stack *pileb)
{
	int		nbr;
	t_node	*node_opti;

	while (pileb->begin)
	{
		node_opti = ft_push_opti(pileA, pileb);
		nbr = ft_nbr_rr(pileA, pileb, node_opti);
		if (nbr)
			while (nbr--)
				ft_rotate_manager(pileA, pileb, "rr\n");
		nbr = ft_nbr_rrr(pileA, pileb, node_opti);
		if (nbr)
			while (nbr--)
				ft_rotate_manager(pileA, pileb, "rrr\n");
		ft_remote(pileA, pileb, node_opti);
	}
}*/

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
				ft_rotate_manager(pileA, pileb, "rr\n");
		nbr = ft_nbr_rrr(pileA, pileb, node_opti);
		if (nbr)
			while (nbr--)
				ft_rotate_manager(pileA, pileb, "rrr\n");
		ft_remote(pileA, pileb, node_opti);
	}
}

int	ft_give_group_interval(t_stack *pile, t_node *node)
{
	int	i;
	int	len;

	i = 0;
	len = (ft_node_max(pile, 1))->index + 1; // maintenant on fai en foction de la mediane
	while (++i <= CHUN1)
		if (node->index < i * len / CHUN1)
			return (i);
	return (0);
}

void	ft_pre_sort_stackb(t_stack *pileA, t_stack *pileb)
{
	t_node	*node_top;
	t_node	*node_bot;
	int		i;

	if (pileb->begin && stack_size(pileb) > 1)
	{
		node_top = ft_find_same_group_from_top(pileA, pileb);
		if (node_top)
		{
			node_bot = ft_find_same_group_from_bottom(pileA, pileb);
			i = node_top->pos;
			if ((float)i < (float)stack_size(pileb) / (float)2 \
			&& i < stack_size(pileb) - node_bot->pos)
				while (i--)
					ft_rotate_manager(NULL, pileb, "rb\n");
			else
			{
				i = stack_size(pileb) - node_bot->pos;
				while (i--)
					ft_rotate_manager(NULL, pileb, "rrb\n");
			}
		}
		else
			ft_regroup_b(pileb);
	}
}
