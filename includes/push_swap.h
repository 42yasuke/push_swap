/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:13:15 by jralph            #+#    #+#             */
/*   Updated: 2023/01/09 22:56:30 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct node
{
	int				data;
	struct node		*prev;
	struct node		*next;
	int				index;
	int				pos;
}	t_node;

typedef struct stack
{
	t_node	*begin;
	t_node	*end;
}	t_stack;

# ifndef CHUN1
#  define CHUN1 2
# endif

/*swap.c*/
void	ft_swap(t_stack *pile);
void	ft_swap_manager(t_stack *pileA, t_stack *pileb, char *str, int print);

/*ft_rotate.c*/
void	ft_rotate_manager(t_stack *pileA, t_stack *pileb, char *str, int print);
void	ft_rotate_manager_else(t_stack *pileA, t_stack *pileb, char *str);
void	ft_rotate(t_stack *pile, char *str);

/*stack.c, stack_utils*/
void	stack_initial(t_stack *pile);
void	stack_push(t_stack *pile, int data, int index);
int		stack_pop(t_stack *pile);
void	stack_clear(t_stack *pile);
int		stack_size(t_stack *pile);
t_stack	*stack_tab(int ac, char **av);

/*sort.c, algo.c*/
int		ft_is_sort(t_stack *pile);
void	ft_sort_after_push(t_stack *pileA);
void	ft_sort(t_stack *pile);

/*algo_utils.c*/
void	ft_five_loop(t_stack *pileA, t_stack *pileb);
void	ft_five_loop2(t_stack *pileA, t_stack *pileb);

/*push.c*/
void	ft_push(t_stack *a, t_stack *b, int is_pa, int print);
void	ft_push_interval5(t_stack *pileA, t_stack *pileb);
t_node	*ft_push_opti(t_stack *pileA, t_stack *pileb);

/*ft_utils.c*/
int		ft_duplicate(int ac, char **av);
int		ft_valide_tab(int ac, char **av, int ckeck);
long	ft_atol(const char *nptr);

/*ft_utils2.c*/
int		ft_nbr_opti(int a, int b, t_stack *pileA, t_stack *pileb);
int		ft_nbr_rr(t_stack *pileA, t_stack *pileb, t_node *node_opti);
int		ft_nbr_rrr(t_stack *pileA, t_stack *pileb, t_node *node_opti);

/*ft_utils3.c*/
void	ft_set_index(t_stack *pile);
void	ft_set_pos(t_stack *pile);

/*ft_utils4.c*/
void	ft_remote(t_stack *pileA, t_stack *pileb, t_node *node_opti);
t_node	*ft_node_max(t_stack *pile, int max);
int		ft_nbig_pos(t_stack *pile, t_node *node_max);
t_node	*ft_find_highest(t_stack *pileA);
t_node	*ft_find_lowest(t_stack *pileA);

/*ft_chaine.c*/
int		ft_chaine(char **av, int check);
t_stack	*ft_chaine2(char **av);

#endif
