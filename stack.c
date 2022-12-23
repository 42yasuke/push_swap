/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:25:39 by jose              #+#    #+#             */
/*   Updated: 2022/12/23 02:30:50 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_utils.h"

void	stack_initial(t_stack *pile)
{
	pile->begin = NULL;
	pile->end = NULL;
}

void	stack_push(t_stack *pile, int data)
{
	t_node		*new;

	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->data = data;
	if (!pile->end)
		pile->end = new;
	else
		pile->end->prev = new;
	new->next = pile->end;
	if (!pile->begin)
		pile->begin = new;
	new->prev = pile->begin;
	pile->begin->next = new;
	new->index = -1;
	pile->begin = new;
	ft_set_pos(pile);
}

int	stack_pop(t_stack *pile)
{
	t_node	*tmp;
	int		ret;
	int		is_last_node;

	tmp = pile->begin;
	ret = 0;
	is_last_node = 0;
	if (stack_size(pile) == 1)
		is_last_node = 1;
	tmp = pile->begin;
	pile->begin = pile->begin->prev;
	pile->end->prev = pile->begin;
	pile->begin->next = pile->end;
	ret = tmp->data;
	free(tmp);
	if (is_last_node)
		stack_initial(pile);
	ft_set_pos(pile);
	return (ret);
}

void	stack_clear(t_stack *pile)
{
	if (!pile->begin)
		return ;
	while (pile->begin)
		stack_pop(pile);
}

int	stack_size(t_stack *pile)
{
	int		ret;
	t_node	*tmp;

	ret = 0;
	if (pile)
	{
		tmp = pile->begin;
		while (tmp && tmp != pile->end)
		{
			ret++;
			tmp = tmp->prev;
		}
	}
	return (++ret);
}
