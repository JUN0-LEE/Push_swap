# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 10:45:36 by julee             #+#    #+#              #
#    Updated: 2019/02/27 20:30:17 by julee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualizer

SRC = checker.c print.c print2.c operation.c dequeue.c dequeue2.c helper.c \
	  helper2.c flag.c read.c

CC = @gcc -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

LIB = ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

$(LIB):
	@cd ../libft && make

clean:
	@rm -rf $(OBJ)
	@cd ../libft && make clean

fclean: clean
	@rm -rf $(NAME)
	@cd ../libft && make fclean

re: fclean all
