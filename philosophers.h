/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:18:24 by knoda             #+#    #+#             */
/*   Updated: 2021/11/28 16:10:10 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#include "libft/libft.h"

typedef struct s_vars {
	int		num;
	int		die;
	int		eat;
	int		sleep;
	int		times;
	long	s_time;

	// int				p_id;
	// pthread_mutex_t *rhs;
	// pthread_mutex_t *lhs;
}				t_vars;

typedef struct s_philosopher {
	int				p_id;
	t_vars			v;
	pthread_mutex_t *rhs;
	pthread_mutex_t *lhs;
}				t_philosopher;

int		parse(int argc, char **argv, t_vars *v);
long	get_time(void);
void	ft_wait(long ms);
