# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sacorder <sacorder@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 18:04:20 by sacorder          #+#    #+#              #
#    Updated: 2023/02/22 15:57:46 by sacorder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
NAME = bsq
FLAGS = -Wall -Wextra -Werror
SRC = main.c file_utils.c matrix_utils.c
OBJ = main.o file_utils.o matrix_utils.o
all = $(NAME)
RM=/bin/rm -f
$(NAME) :$(SRC)
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)
fclean:
	$(RM) $(NAME)
