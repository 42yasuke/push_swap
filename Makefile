# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose <jose@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 14:13:55 by jralph            #+#    #+#              #
#    Updated: 2023/01/05 23:15:21 by jose             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -c

RM = rm -f

LIB = libft/

SRC =	algo.c \
		algo_utils.c \
		ft_rotate.c \
		ft_utils.c \
		ft_utils2.c \
		ft_utils3.c \
		ft_utils4.c \
		push.c \
		sort.c \
		stack_utils.c \
		stack.c \
		swap.c \
		chaine.c

SRC_BONUS = check.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = check.o

NAME = push_swap

all : $(NAME)

lib :
		make bonus -C $(LIB)

%.o : %.c
			$(CC) $(CFLAGS) $< -o $@

$(NAME) : $(OBJ) lib main.o
			$(CC) -o $(NAME) $(OBJ) main.o libft.a
			make clean
			clear

bonus : $(OBJ) $(OBJ_BONUS) lib
			$(CC) -o checker $(OBJ) $(OBJ_BONUS) libft.a
			make clean
			clear

clean :
			$(RM) $(OBJ) $(OBJ_BONUS) main.o
			clear

fclean : clean
			$(RM) $(NAME) libft.a checker
			clear

re : fclean all

.PHONY : all fclean re bonus $(NAME) lib