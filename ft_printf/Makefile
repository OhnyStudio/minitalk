# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 15:01:24 by jsavard           #+#    #+#              #
#    Updated: 2022/11/01 16:40:41 by johnysavard      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c ft_len.c ft_printf_others.c ft_printf_hexa.c\
	ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c
FILEO = $(SRC:.c=.o)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC) -I ./includes
	ar rc $(NAME) $(FILEO)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(FILEO)

fclean: clean
	rm -f $(NAME)

re: fclean all
