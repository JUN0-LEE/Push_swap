# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 16:03:04 by julee             #+#    #+#              #
#    Updated: 2019/03/01 23:15:02 by julee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap

SRC = main.c operation.c dequeue.c dequeue2.c mergesort.c group.c \
      helper.c pushswap1.c pushswap2.c pushswap_log4a.c pushswap_log4b.c \
	  group2.c vec1.c vec2.c check_valid.c freer.c for_small.c for_big.c

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
