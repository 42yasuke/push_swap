/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:39:56 by jose              #+#    #+#             */
/*   Updated: 2022/12/21 07:47:07 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>
# include "stack.h"
# include "libft/libft.h"

int		ft_duplicate(int ac, char **av);
int		ft_valide_tab(int ac, char **av);
t_stack	*stack_tab(int ac, char **av);

#endif