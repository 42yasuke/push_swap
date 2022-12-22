/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:11:36 by jralph            #+#    #+#             */
/*   Updated: 2022/12/22 08:43:33 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static int	ft_is_sort(t_stack **begin)
{
	t_stack	*tmp;
	int		nbr;

	if (begin && *begin)
	{
		tmp = *begin;
		nbr = tmp->data;
		while (tmp->prev)
		{
			if (nbr < tmp->data)
				return (0);
			tmp = tmp->prev;
		}
	}
	return (1);
}

void	ft_little_sort(t_stack **begin)
{
	
}

void	ft_sort(t_stack **begin)
{
	int	size;

	size = stack_size(begin);
	if (size > 1 && size <= 5)
		ft_little_sort(&(*begin));
	else if (size > 5 && size <= 100)
		ft_medium_sort(&(*begin));
	else if (size > 100)
		ft_big_sort(&(*begin));
}
