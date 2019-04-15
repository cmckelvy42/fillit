NAME = fillit

SRC = *.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME):
	@make -C libft fclean
	@make -C libft
	@make -C libft clean
	@echo "\033[32mmaking fillit...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) libft/libft.a

.PHONY: clean
clean:
	@echo "\033[33mcleaning...\033[0m"
	@/bin/rm -f $(NAME)
	@make -C libft fclean

.PHONY: re
re: clean all
