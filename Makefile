# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 17:27:59 by cborrome          #+#    #+#              #
#    Updated: 2024/11/15 15:56:22 by cborrome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = \
		ft_printf.c \
		ft_printf_helper.c

HEAD = ft_printf.h

OBJS = $(SRCS:.c=.o)

AR = ar -rcs

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	 $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
