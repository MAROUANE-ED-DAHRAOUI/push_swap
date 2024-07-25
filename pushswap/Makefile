# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 15:56:55 by med-dahr          #+#    #+#              #
#    Updated: 2024/07/24 15:56:59 by med-dahr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HDER = push_swap.h
SRC =  action.c push_swap.c action1.c check_dup.c convert_num.c init_stack.c utils.c utils1.c join_args.c moves.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME):  $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.c $(HDER)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:clean 