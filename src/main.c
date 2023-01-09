/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:28:49 by jose              #+#    #+#             */
/*   Updated: 2023/01/09 22:59:00 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*pile;

	pile = NULL;
	if (ft_valide_tab(ac, av, 0))
	{
		pile = stack_tab(ac, av);
		if (!pile)
			return (0);
		ft_sort(pile);
		stack_clear(pile);
	}
	free(pile);
	return (0);
}
