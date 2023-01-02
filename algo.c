/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:11:36 by jralph            #+#    #+#             */
/*   Updated: 2023/01/02 11:24:46 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_three_sort(t_stack *pile)
{
	t_node	*tmp_max;

	tmp_max = pile->begin;
	while (tmp_max != ft_node_max(pile, 1))
		tmp_max = tmp_max->prev;
	if (tmp_max == pile->begin)
	{
		ft_rotate_manager(pile, NULL, "ra\n");
		if (!ft_is_sort(pile))
			return (ft_swap_manager(pile, NULL, "sa\n"));
	}
	else if (tmp_max == pile->end && !ft_is_sort(pile))
		return (ft_swap_manager(pile, NULL, "sa\n"));
	else if (!ft_is_sort(pile))
	{
		ft_rotate_manager(pile, NULL, "rra\n");
		if (!ft_is_sort(pile))
			return (ft_swap_manager(pile, NULL, "sa\n"));
	}
}

static void	ft_five_sort(t_stack *pileA)
{
	t_stack	*pileb;

	pileb = malloc(sizeof(*pileb));
	if (!pileb)
		return ;
	stack_initial(pileb);
	while (stack_size(pileA) != 3)
		ft_push(pileA, pileb, 0);
	ft_three_sort(pileA);
	ft_five_loop2(pileA, pileb);
	ft_sort_after_push(pileA);
	free (pileb);
	pileb = NULL;
}

static void	ft_big_sort(t_stack *pileA)
{
	t_stack	*pileb;

	pileb = malloc(sizeof(*pileb));
	if (!pileb)
		return ;
	stack_initial(pileb);
	ft_push_interval5(pileA, pileb);
	ft_three_sort(pileA);
	ft_five_loop2(pileA, pileb);
	ft_sort_after_push(pileA);
	free (pileb);
	pileb = NULL;
}

void	ft_sort(t_stack *pile)
{
	int	size;

	if (ft_is_sort(pile))
		return ;
	size = stack_size(pile);
	if (size > 1 && size <= 3)
		ft_three_sort(pile);
	else if (size > 3 && size <= 5)
		ft_five_sort(pile);
	else if (size > 5)
		ft_big_sort(pile);
}
