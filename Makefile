# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jralph <jralph@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 14:13:55 by jralph            #+#    #+#              #
#    Updated: 2023/01/02 17:08:27 by jralph           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -c

RM = rm -f

LIB = libft/

SRC =	algo.c \
		algo_utils.c \
		ft_rotate.c \
		ft_utils.c \
		ft_utils2.c \
		ft_utils3.c \
		ft_utils4.c \
		main.c \
		push.c \
		sort.c \
		stack_utils.c \
		stack.c \
		swap.c \
		chaine.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = 

NAME = push_swap

all : $(NAME)

lib :
		make -C $(LIB)

%.o : %.c
			$(CC) $(CFLAGS) $< -o $@

$(NAME) : $(OBJ) lib
			$(CC) -o $(NAME) $(OBJ) libft.a

bonus : $(OBJ) $(OBJ_BONUS)

clean :
			$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
			$(RM) $(NAME) libft.a

re : fclean all

.PHONY : all fclean re