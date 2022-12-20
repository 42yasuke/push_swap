/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:19:55 by jose              #+#    #+#             */
/*   Updated: 2022/12/20 12:05:55 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct stack
{
	int				data;
	struct stack	*prev;
}	t_stack;

void	stack_push(t_stack **begin, int data);
t_stack	*stack_pop(t_stack **begin);
void	stack_clear(t_stack **begin);

#endif