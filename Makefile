# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 14:05:59 by vvaltone          #+#    #+#              #
#    Updated: 2019/11/20 10:07:10 by vvaltone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS =	project/main.c\
		project/creator.c\
		project/map.c\
		project/parser.c\
		project/solver.c
OBJS = $(SRCS:.c=.o)
HDR = /project/fillit.h
FLAGS = -Wall -Wextra -Werror

LIBFT = libft/

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HDR) -L. libft/libft.a

clean:
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
