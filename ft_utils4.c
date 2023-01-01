/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:29:01 by jralph            #+#    #+#             */
/*   Updated: 2022/12/30 14:34:21 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_same_group_from_top(t_stack *pileA, t_stack *pileb)
{
	int		i;
	t_node	*tmp;

	i = stack_size(pileb);
	tmp = pileb->begin;
	while (i--)
	{
		if (ft_give_group_interval(pileA, pileA->begin) \
		== ft_give_group_interval(pileA, tmp))
			return (tmp);
		tmp = tmp->prev;
	}
	return (NULL);
}

t_node	*ft_find_same_group_from_bottom(t_stack *pileA, t_stack *pileb)
{
	int		i;
	t_node	*tmp;

	i = stack_size(pileb);
	tmp = pileb->end;
	while (i--)
	{
		if (ft_give_group_interval(pileA, pileA->begin) \
		== ft_give_group_interval(pileA, tmp))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_node	*ft_find_the_first_diff_group(t_stack *pileb)
{
	int		i;
	t_node	*tmp;

	i = stack_size(pileb);
	tmp = pileb->begin;
	while (i--)
	{
		if (ft_give_group_interval(pileb, tmp) != \
		ft_give_group_interval(pileb, tmp->prev))
			return (tmp->prev);
		tmp = tmp->prev;
	}
	return (NULL);
}

void	ft_regroup_b(t_stack *pileb)
{
	int		i;
	t_node	*node_top;

	node_top = ft_find_the_first_diff_group(pileb);
	if (!node_top)
		return ;
	i = node_top->pos;
	if ((float)i < (float)stack_size(pileb) / (float)2)
		while (i-- > -1)
			ft_rotate_manager(NULL, pileb, "rb\n");
	else
	{
		i = stack_size(pileb) - node_top->pos;
		while (i-- > -1)
			ft_rotate_manager(NULL, pileb, "rrb\n");
	}
}
