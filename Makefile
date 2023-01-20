# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jralph <jralph@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 14:13:55 by jralph            #+#    #+#              #
#    Updated: 2023/01/20 19:01:25 by jralph           ###   ########.fr        #
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

libft.a :
			make bonus -C $(LIB)

main.o : src/main.c
			$(CC) $(CFLAGS) $< -o $@ $(INC)

check_bonus.o : src/check_bonus.c
			$(CC) $(CFLAGS) $< -o $@ $(INC)

$(NAME) : $(OBJ) main.o libft.a
			$(CC) -o $(NAME) $(OBJ) main.o libft.a

checker : $(OBJ) check_bonus.o libft.a
			$(CC) -o checker $(OBJ) check_bonus.o libft.a

bonus : checker

clean :
			make clean -C $(LIB)
			$(RM) $(OBJ) check_bonus.o main.o

fclean : clean
			$(RM) $(NAME) libft.a checker

re : fclean all

.PHONY : all fclean re clean bonus
