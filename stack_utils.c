/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 01:30:06 by jralph            #+#    #+#             */
/*   Updated: 2023/01/02 17:40:50 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_tab(int ac, char **av)
{
	int		i;
	t_stack	*pile;

	i = ac;
	if (ac == 2)
		return (ft_chaine2(av));
	pile = malloc(sizeof(*pile));
	if (!pile)
		return (NULL);
	stack_initial(pile);
	while (--i > 0)
		stack_push(pile, ft_atoi(av[i]), -1);
	ft_set_index(pile);
	return (pile);
}
