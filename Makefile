# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jralph <jralph@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 14:13:55 by jralph            #+#    #+#              #
#    Updated: 2023/01/09 22:00:58 by jralph           ###   ########.fr        #
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


OBJ = $(SRC:.c=.o)

NAME = push_swap

all : $(NAME)

%.o : %.c
			$(CC) $(CFLAGS) $< -o $@ $(INC)

main.o : src/main.c
			$(CC) $(CFLAGS) $< -o $@ $(INC)

check.o : src/check.c
			$(CC) $(CFLAGS) $< -o $@ $(INC)

$(NAME) : $(OBJ) main.o
			make bonus -C $(LIB)
			$(CC) -o $(NAME) $(OBJ) main.o libft.a

checker : $(OBJ) check.o
			$(CC) -o checker $(OBJ) check.o libft.a

bonus : checker

clean :
			make clean -C $(LIB)
			$(RM) $(OBJ) check.o main.o

fclean : clean
			$(RM) $(NAME) libft.a checker

re : fclean all

.PHONY : all fclean re clean bonus
