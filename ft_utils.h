/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:42:57 by jralph            #+#    #+#             */
/*   Updated: 2022/12/22 19:53:15 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "algo.h"

int		ft_duplicate(int ac, char **av);
int		ft_valide_tab(int ac, char **av);
t_stack	*stack_tab(int ac, char **av);
void	ft_set_index(t_stack *pile);
void	ft_set_pos(t_stack *pile);

#endif