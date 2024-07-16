NAME = push_swap

HDER = src/push_swap.h

SRC = \
	src/action.c\
	src/push_swap.c\
	src/action1.c\
	src/check_dup.c\
	src/convert_num.c\
	src/init_stack.c\
	src/utils.c\
	src/utils1.c\
	src/join_args.c\
	src/moves.c\

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ) $(HDER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all
