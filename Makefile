# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knoda <knoda@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 12:16:30 by knoda             #+#    #+#              #
#    Updated: 2021/12/02 15:07:02 by knoda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philosophers
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address
SRCS := main.c parse.c get_time.c ft_wait.c ft_isdigit.c ft_atoi.c\
 ft_strncmp.c launch_threads.c do_monitor.c do_philo.c is_full.c mutex_print.c
OBJS := $(SRCS:.c=.o)


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
