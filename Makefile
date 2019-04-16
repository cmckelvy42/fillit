# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 19:17:23 by elhampto          #+#    #+#              #
#    Updated: 2019/04/14 22:45:51 by elhampto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = board.c clean.c helper.c main.c read.c tetriminos.c

OBJ = board.o clean.o helper.o main.o read.o tetriminos.o

INC = fillit.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) -c $(SRC) -I $(INC)
	@echo "\x1b[31m.O files created"
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L ./libft/ -lft
	@echo "\x1b[35mNamed as fillit"

clean:
	@make -C libft clean
	@rm -rf $(OBJ)
	@echo "\x1b[34mAll .O files erased"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "\x1b[35m\nAll .O files & Libary erased\n"

re: fclean all

.PHONY: all, clean, fclean, re
