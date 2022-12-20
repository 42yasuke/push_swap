/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:19:55 by jose              #+#    #+#             */
/*   Updated: 2022/12/20 23:42:54 by jralph           ###   ########.fr       */
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
int		stack_pop(t_stack **begin);
void	stack_clear(t_stack **begin);
int		stack_size(t_stack **begin);

#endif