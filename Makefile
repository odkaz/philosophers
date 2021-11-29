# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knoda <knoda@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 12:16:30 by knoda             #+#    #+#              #
#    Updated: 2021/11/28 17:03:03 by knoda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philosophers
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address
SRCS := main.c parse.c get_time.c ft_wait.c
OBJS := $(SRCS:.c=.o)


all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) -L. -lft -o $(NAME)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) libft.a

re: fclean all
