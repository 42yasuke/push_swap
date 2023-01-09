/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:36:33 by jralph            #+#    #+#             */
/*   Updated: 2023/01/09 22:58:28 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				return (write (2, "Error\n", 6), 0);
			j++;
		}
		j = 0;
		while (ft_isdigit(av[i][j]) || av[i][j] == ' ')
			j++;
		if (av[i][j] && av[i][j] != '-' && av[i][j] != '+')
			return (write (2, "Error\n", 6), 0);
		i++;
	}
	return (1);
}

int	ft_valide_tab(int ac, char **av, int check)
{
	int		i;

	i = 1;
	if (ac == 1)
		return (0);
	if (ac == 2)
		return (ft_chaine(av, check));
	while (av[i])
	{
		if (ft_strlen(av[i]) > 11)
			return (write (2, "Error\n", 6), 0);
		if (ft_atol(av[i]) == 0 && (ft_strlen(av[i]) > 2 || av[i][0] != '0'))
			return (write (2, "Error\n", 6), 0);
		else if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (write (2, "Error\n", 6), 0);
		i++;
	}
	return (ft_duplicate(ac, av));
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
