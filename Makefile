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

INC = -I includes/

SRC =	src/algo.c \
		src/algo_utils.c \
		src/ft_rotate.c \
		src/ft_utils.c \
		src/ft_utils2.c \
		src/ft_utils3.c \
		src/ft_utils4.c \
		src/push.c \
		src/sort.c \
		src/stack_utils.c \
		src/stack.c \
		src/swap.c \
		src/chaine.c

SRC_BONUS = src/check.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = push_swap

all : $(NAME)

lib :
		make bonus -C $(LIB)

%.o : %.c
			$(CC) $(CFLAGS) $< -o $@ $(INC)
			
main.o : src/main.c
			$(CC) $(CFLAGS) $< -o $@ $(INC)

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
