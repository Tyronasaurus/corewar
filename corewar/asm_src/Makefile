# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/14 14:46:37 by cpauwels          #+#    #+#              #
#    Updated: 2017/09/13 09:49:04 by cpauwels         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
SRC = main.c error.c text.c hex.c file.c check.c print.c reverse.c \
	  ft_atoi_base.c split.c ft_convert.c \
	  ft_get_lbl.c ft_get_parems.c ft_getacb.c ft_hex_lbl.c ft_link.c \
	  ft_list.c ft_misc.c ft_misc2.c ft_valid.c op.c
INC = ../libft/libft.a
CC = gcc
FLAG = -Wall -Werror -Wextra

all:
	$(CC) -o $(NAME) $(SRC) $(FLAG) $(INC)
	rm -f *.cor

clean:
	rm -f $(NAME)

fclean: clean
	rm -f *.cor
