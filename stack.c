/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:25:39 by jose              #+#    #+#             */
/*   Updated: 2022/12/20 12:06:48 by jralph           ###   ########.fr       */
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
	begin = &new;
}

t_stack	*stack_pop(t_stack **begin)
{
	t_stack	*tmp;

	tmp = NULL;
	if (begin && *begin)
	{
		tmp = *begin;
		*begin = (*begin)->prev;
	}
	return (tmp);
}

void	stack_clear(t_stack **begin)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!begin)
		return ;
	while (*begin)
	{
		tmp = *begin;
		*begin = (*begin)->prev;
		free(tmp);
		tmp = NULL;
	}
}
