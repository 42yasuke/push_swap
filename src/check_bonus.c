/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:45:11 by jralph            #+#    #+#             */
/*   Updated: 2023/01/20 19:38:19 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_good_chaine(char *line)
{
	size_t	i;

	i = ft_strlen(line);
	if (!ft_strncmp(line, "sa\n", i) || !ft_strncmp(line, "sb\n", i) || \
		!ft_strncmp(line, "ss\n", i) || !ft_strncmp(line, "ra\n", i) || \
		!ft_strncmp(line, "rb\n", i) || !ft_strncmp(line, "rr\n", i) || \
		!ft_strncmp(line, "rra\n", i) || !ft_strncmp(line, "rrb\n", i) \
		|| !ft_strncmp(line, "rrr\n", i) || \
		!ft_strncmp(line, "pa\n", i) || !ft_strncmp(line, "pb\n", i))
		return (1);
	return (0);
}

static t_list	*ft_valide_commande(int fd, int *is_there_only_good_inst)
{
	char	*line;
	t_list	*begin;
	int		is_good;

	line = get_next_line(fd);
	begin = NULL;
	is_good = 1;
	while (line)
	{
		if (ft_is_good_chaine(line))
			ft_lstadd_back(&begin, ft_lstnew(line));
		else
		{
			free(line);
			is_good = 0;
		}
		line = get_next_line(fd);
	}
	*is_there_only_good_inst = is_good;
	if (!is_good)
		return (free(line), ft_lstclear(&begin, &free), \
		write (2, "Error\n", 6), NULL);
	return (begin);
}

static void	ft_sort_manager2(t_stack *pileA, t_stack *pileb, char *str)
{
	if (!ft_strncmp(str, "sa\n", ft_strlen(str)))
		ft_swap_manager(pileA, NULL, str, 0);
	else if (!ft_strncmp(str, "sb\n", ft_strlen(str)))
		ft_swap_manager(NULL, pileb, str, 0);
	else if (!ft_strncmp(str, "ss\n", ft_strlen(str)))
		ft_swap_manager(pileA, pileb, str, 0);
	else if (!ft_strncmp(str, "ra\n", ft_strlen(str)))
		ft_rotate_manager(pileA, NULL, str, 0);
	else if (!ft_strncmp(str, "rb\n", ft_strlen(str)))
		ft_rotate_manager(NULL, pileb, str, 0);
	else if (!ft_strncmp(str, "rr\n", ft_strlen(str)))
		ft_rotate_manager(pileA, pileb, str, 0);
	else if (!ft_strncmp(str, "rra\n", ft_strlen(str)))
		ft_rotate_manager(pileA, NULL, str, 0);
	else if (!ft_strncmp(str, "rrb\n", ft_strlen(str)))
		ft_rotate_manager(NULL, pileb, str, 0);
	else if (!ft_strncmp(str, "rrr\n", ft_strlen(str)))
		ft_rotate_manager(pileA, pileb, str, 0);
	else if (!ft_strncmp(str, "pa\n", ft_strlen(str)))
		ft_push(pileA, pileb, 1, 0);
	else if (!ft_strncmp(str, "pb\n", ft_strlen(str)))
		ft_push(pileA, pileb, 0, 0);
}

static void	ft_sort_manager(t_stack *pileA, t_stack *pileb, int fd)
{
	t_list	*begin;
	t_list	*tmp;
	int		is_there_only_good_inst;

	begin = ft_valide_commande(fd, &is_there_only_good_inst);
	tmp = begin;
	while (tmp)
	{
		ft_sort_manager2(pileA, pileb, (char *)(tmp->content));
		tmp = tmp->next;
	}
	if (!begin && !is_there_only_good_inst)
		return ;
	if (begin)
		ft_lstclear(&begin, &free);
	if (ft_is_sort(pileA) && !pileb->begin)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*pilea;
	t_stack	*pileb;

	pilea = NULL;
	pileb = malloc(sizeof(*pileb));
	if (!pileb)
		return (0);
	stack_initial(pileb);
	if (ft_valide_tab(ac, av, 1))
	{
		pilea = stack_tab(ac, av);
		if (!pilea)
			return (free(pileb), 0);
		ft_sort_manager(pilea, pileb, STDIN_FILENO);
		stack_clear(pilea);
		stack_clear(pileb);
	}
	return (free(pilea), free(pileb), 0);
}
