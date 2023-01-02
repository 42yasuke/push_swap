/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:07:57 by jralph            #+#    #+#             */
/*   Updated: 2023/01/02 18:12:46 by jralph           ###   ########.fr       */
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
	free(res[i]);
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

int	ft_chaine(char **av)
{
	char	**str;
	char	**str_copy;
	int		i;
	int		ret;

	i = 1;
	str = ft_split(av[1], ' ');
	str_copy = malloc(sizeof(*str)*(ft_nb_nbr(str) + 2));
	str_copy[0] = malloc(sizeof(char));
	str_copy[0][0] = 'K';
	while (str[i - 1])
	{
		str_copy[i] = str[i - 1];
		i++;
	}
	str_copy[i] = NULL;
	ret = ft_valide_tab(ft_nb_nbr(str_copy), str_copy);
	ft_freeall(str);
	free(str_copy[0]);
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
	str_copy = malloc(sizeof(*str)*(ft_nb_nbr(str) + 2));
	str_copy[0] = malloc(sizeof(char));
	str_copy[0][0] = 'K';
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
