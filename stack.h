/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:19:55 by jose              #+#    #+#             */
/*   Updated: 2022/12/19 15:11:47 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct stack
{
	int				data;
	struct stack	*prev;
}	stack;

void	stack_push(stack **begin, int data);
stack	*stack_pop(stack **begin);
void	stack_clear(stack **begin);