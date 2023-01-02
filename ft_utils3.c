/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:44:25 by jralph            #+#    #+#             */
/*   Updated: 2023/01/02 09:52:40 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index(t_stack *pile)
{
	static int	i = 0;
	static int	j = 0;
	int			len_stack;
	t_node		*tmp;
	t_node		*tmp_min;

	tmp = pile->begin;
	tmp_min = tmp;
	len_stack = stack_size(pile);
	while (i < len_stack)
	{
		while (j < len_stack)
		{
			if (tmp_min->index != -1 && tmp->index == -1)
				tmp_min = tmp;
			if (tmp->index == -1 && tmp->data < tmp_min->data)
				tmp_min = tmp;
			tmp = tmp->prev;
			j++;
		}
		j = 0;
		tmp_min->index = i;
		tmp = pile->begin;
		i++;
	}
}

void	ft_set_pos(t_stack *pile)
{
	int		i;
	t_node	*tmp;

	if (!pile)
		return ;
	i = 0;
	tmp = pile->begin;
	if (!tmp)
		return ;
	while (tmp != pile->end)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->prev;
	}
	tmp->pos = i;
}
