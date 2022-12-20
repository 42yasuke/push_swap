/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:28:49 by jose              #+#    #+#             */
/*   Updated: 2022/12/20 18:59:51 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_duplicate(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (av[i][0] == av[j][0])
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
		if (ft_strlen(av[i]) > 2 || (val == 0 && av[i][0] != '0'))
		{
			write (2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (ft_duplicate(ac, av));
}

void	stack_tab(int ac, char **av, t_stack **begin, t_stack **end)
{
	int	i;

	i = ac - 1;
	while (i > -1)
	{
		stack_push(begin, ft_atoi(av[i]));
		i--;
	}
}

int	main(int ac, char **av)
{
	t_stack	*begin;

	begin = NULL;
	if (ft_valide_tab(ac, av))
	{
		stack_tab(ac, av, &begin);
	}
	return (0);
}
