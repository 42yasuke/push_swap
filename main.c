/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:28:49 by jose              #+#    #+#             */
/*   Updated: 2022/12/21 06:17:34 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_duplicate(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				write (2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_valide_tab(int ac, char **av)
{
	int	i;
	int	val;

	i = 1;
	val = 0;
	if (ac == 1)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	while (av[i])
	{
		val = ft_atoi(av[i]);
		if (val == 0 && (ft_strlen(av[i]) > 2 || av[i][0] != '0'))
		{
			write (2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (ft_duplicate(ac, av));
}

t_stack	*stack_tab(int ac, char **av)
{
	int	i;
	t_stack	*begin;

	i = ac - 1;
	begin = NULL;
	while (i > 0)
	{
		stack_push(&begin, ft_atoi(av[i]));
		i--;
	}
	return (begin);
}

int	main(int ac, char **av)
{
	t_stack	*begin_a;

	begin_a = NULL;
	if (ft_valide_tab(ac, av))
	{
		begin_a = stack_tab(ac, av);
	}
	stack_clear(&begin_a);
	return (0);
}
