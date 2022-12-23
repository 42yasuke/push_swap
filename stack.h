/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:19:55 by jose              #+#    #+#             */
/*   Updated: 2022/12/23 08:51:53 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct node
{
	int				data;
	struct node		*prev;
	struct node		*next;
	int				index;
	int				pos;
}	t_node;

typedef struct stack
{
	t_node	*begin;
	t_node	*end;
}	t_stack;

void	stack_initial(t_stack *pile);
void	stack_push(t_stack *pile, int data);
int		stack_pop(t_stack *pile);
void	stack_clear(t_stack *pile);
int		stack_size(t_stack *pile);

#endif