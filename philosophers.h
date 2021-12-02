/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:18:24 by knoda             #+#    #+#             */
/*   Updated: 2021/12/02 15:06:38 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

typedef struct s_vars {
	int		num;
	int		die;
	int		eat;
	int		sleep;
	int		times;
	long	s_time;
	int		*someone_is_dead;
}				t_vars;

typedef struct s_philosopher {
	int						p_id;
	long					last_meal;
	int						eat_cnt;
	t_vars					*v;
	pthread_mutex_t			*rhs;
	pthread_mutex_t			*lhs;
	pthread_mutex_t			*w_mtx;
	struct s_philosopher	*all;
}				t_philosopher;

int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		parse(int argc, char **argv, t_vars *v);
int		is_full(t_philosopher *p);
void	mutex_print(t_philosopher *p, int msg);
void	*do_philo(void *arg);
void	*do_monitor(void *arg);
int		launch_threads(pthread_t *thread, \
pthread_mutex_t *mutex, t_vars *v, t_philosopher *p);
long	get_time(void);
void	ft_wait(long ms);

enum	e_msg{
	EAT,
	SLEEP,
	THINK,
	DEAD	
};
#endif
