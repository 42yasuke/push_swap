/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:05:42 by jralph            #+#    #+#             */
/*   Updated: 2022/12/30 22:19:06 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_after_push(t_stack *pileA)
{
	int	nbr;

	nbr = (ft_node_max(pileA, 0))->pos;
	if ((float)stack_size(pileA) / (float)2 > (float)nbr)
		while (nbr--)
			ft_rotate_manager(pileA, NULL, "ra\n");
	else
	{
		nbr = stack_size(pileA) - nbr;
		while (nbr--)
			ft_rotate_manager(pileA, NULL, "rra\n");
	}
}

void	ft_five_loop(t_stack *pileA, t_stack *pileb)
{
	int	nbr;

	if (pileb->begin->data > (ft_node_max(pileA, 1))->data)
	{
		ft_sort_after_push(pileA);
		ft_push(pileA, pileb, 1);
		ft_rotate_manager(pileA, NULL, "ra\n");
	}
	else
	{
		nbr = ft_nbig_pos(pileA, pileb->begin);
		if ((float)stack_size(pileA) / (float)2 > (float)nbr)
			while (nbr--)
				ft_rotate_manager(pileA, NULL, "ra\n");
		else
		{
			nbr = stack_size(pileA) - nbr;
			while (nbr--)
				ft_rotate_manager(pileA, NULL, "rra\n");
		}
		ft_push(pileA, pileb, 1);
	}
}

t_node	*ft_find_highest(t_stack *pileA)
{
	t_node	*tmp;
	int		len;
	int		i;

	len = (ft_node_max(pileA, 1))->index + 1;
	i = len;
	tmp = pileA->begin;
	while (i--)
	{
		if (tmp->index < len - 3)
			return (tmp);
		tmp = tmp->prev;
	}
	return (NULL);
}

t_node	*ft_find_lowest(t_stack *pileA)
{
	t_node	*tmp;
	int		len ;
	int		i;

	len = (ft_node_max(pileA, 1))->index + 1;
	i = stack_size(pileA);
	tmp = pileA->end;
	while (i--)
	{
		if (tmp->index < len - 3)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

/*void	ft_push_interval5(t_stack *pileA, t_stack *pileb, int i, int *count)
{
	t_node	*highest;
	t_node	*lowest;
	int		len;

	len = (ft_node_max(pileA, 1))->index + 1;
	while (stack_size(pileA) != 3) 
	{
		highest = ft_find_highest(pileA);
		lowest = ft_find_lowest(pileA);
		if (highest)
		{
			if(highest->pos <= stack_size(pileA) - lowest->pos)
				while (pileA->begin != highest)
					ft_rotate_manager(pileA, NULL, "ra\n");
			else 
				while (pileA->begin != lowest)
					ft_rotate_manager(pileA, NULL, "rra\n");
		}
		ft_push(pileA, pileb, 0);
		ft_pre_sort_stackb(pileA, pileb);
	}
}*/

void	ft_push_interval5(t_stack *pileA, t_stack *pileb)
{
	t_node	*node_top;
	t_node	*node_low;
	int		len;
	int		i;

	len = stack_size(pileA);
	while (stack_size(pileA) != 3)
	{
		node_top = ft_find_highest(pileA);
		node_low = ft_find_lowest(pileA);
		if (!node_top)
			break ;
		i = node_top->pos;
		if ((float)i < (float)stack_size(pileA) / (float)2)
			while (i--)
				ft_rotate_manager(pileA, NULL, "ra\n");
		else
		{
			i = node_low->pos;
			while (i--)
				ft_rotate_manager(pileA, NULL, "rra\n");
		}
		ft_push(pileA, pileb, 0);
		if ((float)pileb->begin->index < (float)len / (float)2)
			ft_rotate_manager(NULL, pileb, "rb\n");
	}
}
