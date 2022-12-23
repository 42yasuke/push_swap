/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:36:33 by jralph            #+#    #+#             */
/*   Updated: 2022/12/23 02:48:18 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

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
	int		i;
	t_stack	*pile;

	i = ac - 1;
	pile = malloc(sizeof(*pile));
	if (!pile)
		return (NULL);
	stack_initial(pile);
	while (i > 0)
	{
		stack_push(pile, ft_atoi(av[i]));
		i--;
	}
	ft_set_index(pile);
	return (pile);
}

void	ft_set_index(t_stack *pile)
{
	static int	i = 0;
	static int	j = 0;
	int			len_stack;
	t_node		*tmp;
	t_node		*tmp_min;

	tmp = pile->begin;
	tmp_min = tmp;
	len_stack = stack_size(pile);
	while (i < len_stack)
	{
		while (j < len_stack)
		{
			if (tmp_min->index != -1 && tmp->index == -1)
				tmp_min = tmp;
			if (tmp->index == -1 && tmp->data < tmp_min->data)
				tmp_min = tmp;
			tmp = tmp->prev;
			j++;
		}
		j = 0;
		tmp_min->index = i;
		tmp = pile->begin;
		i++;
	}
}

void	ft_set_pos(t_stack *pile)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = pile->begin;
	if (!tmp)
		return ;
	while (tmp != pile->end)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->prev;
	}
	tmp->pos = i;
}
