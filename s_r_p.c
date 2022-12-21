/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_r_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:48:04 by jralph            #+#    #+#             */
/*   Updated: 2022/12/21 05:10:53 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_r_p.h"

void	ft_swap(t_stack **begin, char c)
{
	int	tmp;

	tmp = 0;
	if (stack_size(begin) > 1)
	{
		tmp = (*begin)->data;
		(*begin)->data = (*begin)->prev->data;
		(*begin)->prev->data = tmp;
		if (c == 'a')
			write (1, "sa\n", 3);
		else
			write (1, "sb\n", 3);
	}
}

void	ft_push(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
	{
		if (!b)
			return ;
		stack_push(a, stack_pop(b));
		write (1, "pa\n", 3);
	}
	else
	{
		if (!a)
			return ;
		stack_push(b, stack_pop(a));
		write (1, "pb\n", 3);
	}
}

static void	tab_rotate(int	**tabl, int len)
{
	int	i;
	int	tmp;
	int	tmp2;
	int	*tab;

	tab = *tabl;
	i = len -1;
	tmp = tab[i];
	tab[i] = tab[0];
	while (i > 0)
	{
		tmp2 = tab[i - 1];
		tab[i - 1] = tmp;
		tmp = tmp2;
		i--;
	}
}

static void	tab_rrotate(int	**tabl, int len)
{
	int	i;
	int	tmp;
	int	tmp2;
	int	*tab;

	tab = *tabl;
	i = 0;
	tmp = tab[i];
	tab[i] = tab[len - 1];
	while (i < len - 1)
	{
		tmp2 = tab[i + 1];
		tab[i + 1] = tmp;
		tmp = tmp2;
		i++;
	}
}

void	ft_rotate(t_stack **begin, char *str)
{
	int		*tab;
	int		i;
	t_stack	*tmp;

	tab = NULL;
	i = 0;
	tmp = *begin;
	tab = malloc (sizeof(*tab) * stack_size(begin));
	while (tmp)
	{
		tab[i++] = (tmp)->data;
		tmp = (tmp)->prev;
	}
	if (str[1] == 'r')
		tab_rrotate(&tab, stack_size(begin));
	else
		tab_rotate(&tab, stack_size(begin));
	i = 0;
	while (*begin)
	{
		(*begin)->data = tab[i++];
		*begin = (*begin)->prev;
	}
	free(tab);
	write(1, str, ft_strlen(str));
}
