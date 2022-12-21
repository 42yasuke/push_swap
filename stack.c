/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:25:39 by jose              #+#    #+#             */
/*   Updated: 2022/12/21 07:42:37 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_push(t_stack **begin, int data)
{
	t_stack	*new;

	new = NULL;
	if (!begin)
		return ;
	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->data = data;
	new->prev = *begin;
	*begin = new;
}

int	stack_pop(t_stack **begin)
{
	t_stack	*tmp;
	int		ret;
	int		is_last_node;

	tmp = *begin;
	ret = 0;
	is_last_node = 0;
	if (begin && *begin)
	{
		if (stack_size(&tmp) == 1)
			is_last_node = 1;
		tmp = *begin;
		*begin = (*begin)->prev;
		ret = tmp->data;
		free(tmp);
		if (is_last_node)
			*begin = NULL;
	}
	return (ret);
}

void	stack_clear(t_stack **begin)
{
	if (!begin)
		return ;
	while (*begin)
		stack_pop(&(*begin));
}

int	stack_size(t_stack **begin)
{
	int	ret;

	ret = 0;
	if (begin)
	{
		while (*begin)
		{
			ret++;
			*begin = (*begin)->prev;
		}
	}
	return (ret);
}
