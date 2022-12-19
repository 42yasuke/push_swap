/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:25:39 by jose              #+#    #+#             */
/*   Updated: 2022/12/19 15:21:40 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_push(stack **begin, int data)
{
	stack	*new;

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

stack	*stack_pop(stack **begin)
{
	stack	*tmp;

	tmp = NULL;
	if (begin && *begin)
	{
		tmp = *begin;
		*begin = (*begin)->prev;
	}
	return (tmp);
}

void	stack_clear(stack **begin)
{
	stack	*tmp;

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
