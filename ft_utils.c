/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:36:33 by jralph            #+#    #+#             */
/*   Updated: 2023/01/01 00:41:04 by jralph           ###   ########.fr       */
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
		if (av[i][j])
			return (write (2, "Error\n", 6), 0);
		i++;
	}
	return (1);
}

int	ft_valide_tab(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac == 1)
		return (0);
	while (av[i])
	{
		if (ft_atol(av[i]) == 0 && (ft_strlen(av[i]) > 2 || av[i][0] != '0'))
			return (write (2, "Error\n", 6), 0);
		else if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (write (2, "Error\n", 6), 0);
		i++;
	}
	return (ft_duplicate(ac, av));
}

t_stack	*stack_tab(int ac, char **av)
{
	int		i;
	t_stack	*pile;

	i = ac;
	pile = malloc(sizeof(*pile));
	if (!pile)
		return (NULL);
	stack_initial(pile);
	while (--i > 0)
		stack_push(pile, ft_atoi(av[i]), -1);
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

	if(!pile)
		return ;
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
