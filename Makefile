NAME=pipex
SRC=utils.c pipex.c
CC=clang
LIBFT=./libft/libft.a
CFLAGS=-Wall -Wextra -Werror -O3 -g3

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) -I. -Ilibft -o $(NAME) $(SRC) $(LIBFT)

$(LIBFT):
	make -C ./libft

clean:
	make -C ./libft clean

fclean:
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
