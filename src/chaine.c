/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:07:57 by jralph            #+#    #+#             */
/*   Updated: 2023/01/20 14:54:42 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_freeall(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	ft_nb_nbr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_chaine_else_if(char **av)
{
	if (ft_atol(av[1]) > INT_MAX || ft_atol(av[1]) < INT_MIN)
		write (2, "Error\n", 6);
	else
		write (1, "OK\n", 3);
}

int	ft_chaine(char **av, int check)
{
	char		**str;
	char		**str_copy;
	static int	i = 0;
	static int	ret = 0;

	str = ft_split(av[1], ' ');
	str_copy = malloc(sizeof(*str) * (ft_nb_nbr(str) + 2));
	if (!str_copy)
		return (ft_freeall(str), 0);
	str_copy[0] = malloc(sizeof(char));
	if (!str_copy[0])
		return (ft_freeall(str), ft_freeall(str_copy), 0);
	str_copy[0][0] = 0;
	while (++i && str[i - 1])
		str_copy[i] = str[i - 1];
	str_copy[i] = NULL;
	if (i > 2)
		ret = ft_valide_tab(ft_nb_nbr(str_copy), str_copy, 0);
	else if (ft_duplicate(ft_nb_nbr(str_copy), str_copy) && check)
		ft_chaine_else_if(av);
	(ft_freeall(str), free(str_copy[0]));
	return (free(str_copy), ret);
}

t_stack	*ft_chaine2(char **av)
{
	char	**str;
	char	**str_copy;
	int		i;
	t_stack	*ret;

	i = 1;
	str = ft_split(av[1], ' ');
	str_copy = malloc(sizeof(*str) * (ft_nb_nbr(str) + 2));
	if (!str_copy)
		return (ft_freeall(str), NULL);
	str_copy[0] = malloc(sizeof(char));
	if (!str_copy[0])
		return (ft_freeall(str), ft_freeall(str_copy), NULL);
	str_copy[0][0] = 0;
	while (str[i - 1])
	{
		str_copy[i] = str[i - 1];
		i++;
	}
	str_copy[i] = NULL;
	ret = stack_tab(ft_nb_nbr(str_copy), str_copy);
	ft_freeall(str);
	free(str_copy[0]);
	return (free(str_copy), ret);
}
