/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:28:49 by jose              #+#    #+#             */
/*   Updated: 2022/12/30 22:25:39 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	affiche(t_stack *pile)
{
	int		i;
	t_node	*tmp;

	i = stack_size(pile);
	tmp = pile->begin;
	while (i--)
	{
		printf("%d ", tmp->data);
		tmp = tmp->prev;
	}
	printf("\n");
}

int	ft_is_sort(t_stack *pile)
{
	t_node	*tmp;
	int		nbr;

	tmp = pile->begin;
	nbr = tmp->data;
	while (tmp->prev != pile->begin)
	{
		if (nbr > tmp->prev->data)
			return (0);
		nbr = tmp->prev->data;
		tmp = tmp->prev;
	}
	return (1);
}

long	ft_atol(const char *nptr)
{
	long	i;
	long	res;
	long	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_push_interval11(t_stack *pileA, t_stack *pileb, int i, int *count)
{
	t_node	*highest;
	t_node	*lowest;
	int		len;

	len = (ft_node_max(pileA, 1))->index + 1;
	while ((*count) < i * len / CHUN2 && stack_size(pileA) != 3)
	{
		highest = ft_find_highest(pileA);
		lowest = ft_find_lowest(pileA);
		if ((highest->index < i * len / CHUN1) \
		&& (highest->pos < stack_size(pileA) - lowest->pos))
		{
			while (pileA->begin != highest)
				ft_rotate_manager(pileA, NULL, "ra\n");
		}
		else if (lowest->index < i * len / CHUN1)
		{
			while (pileA->begin != lowest)
				ft_rotate_manager(pileA, NULL, "rra\n");
		}
		ft_push(pileA, pileb, 0);
		(*count)++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*pile;

	pile = NULL;
	if (ft_valide_tab(ac, av))
	{
		pile = stack_tab(ac, av);
		if (!pile)
			return (0);
		ft_sort(pile);
		//affiche(pile);/*gcc -Wall -Wextra -Werror *.c -L. -lft -g*/
		stack_clear(pile);
	}
	free(pile);
	return (0);
}
