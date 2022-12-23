/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:28:49 by jose              #+#    #+#             */
/*   Updated: 2022/12/23 10:07:22 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	}
	stack_clear(pile);
	free(pile);
	return (0);
}
