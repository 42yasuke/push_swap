/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_r_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:52:45 by jralph            #+#    #+#             */
/*   Updated: 2022/12/23 14:03:26 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_R_P_H
# define S_R_P_H

# include <unistd.h>
# include "stack.h"
# include "libft/libft.h"
# include "ft_utils.h"

void	ft_swap(t_stack *pile, int is_stack_a);
void	ft_push(t_stack *a, t_stack *b, int is_pa);
void	ft_rotate(t_stack *pile, char *str);

/*on a plus de place ailleurs*/
int	ft_data_max(t_stack *pile, int max);
t_node	*ft_nbig_pos(t_stack *pile, int data);

#endif