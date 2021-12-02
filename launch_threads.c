/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:58:03 by knoda             #+#    #+#             */
/*   Updated: 2021/12/02 15:18:30 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo(t_philosopher *p, t_vars *v, \
pthread_mutex_t *mutex, int i)
{
	p[i].p_id = i;
	p[i].v = v;
	p[i].last_meal = v->s_time;
	p[i].eat_cnt = 0;
	p[i].all = p;
	if (i == 0)
		p[i].lhs = &(mutex[v->num - 1]);
	else
		p[i].lhs = &(mutex[i - 1]);
	p[i].rhs = mutex + i;
}

int	launch_threads(pthread_t *thread, \
pthread_mutex_t *mutex, t_vars *v, t_philosopher *p)
{
	int				i;
	pthread_mutex_t	w_mutex;

	pthread_mutex_init(&w_mutex, NULL);
	i = 0;
	while (i < v->num)
	{
		init_philo(p, v, mutex, i);
		p[i].w_mtx = &w_mutex;
		if (pthread_create(thread + i, NULL, &do_philo, (void *)(p + i)) != 0)
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
