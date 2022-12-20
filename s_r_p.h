/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_r_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:52:45 by jralph            #+#    #+#             */
/*   Updated: 2022/12/20 23:41:59 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_R_P_H
# define S_R_P_H

# include <unistd.h>
# include "stack.h"
# include "libft/libft.h"

void	ft_swap(t_stack **begin, char c);
void	ft_push(t_stack **a, t_stack **b, char c);
void	ft_rotate(t_stack **begin, char *str);

#endif