/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:59:47 by knoda             #+#    #+#             */
/*   Updated: 2021/12/02 15:20:43 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_philosopher *p)
{
	pthread_mutex_lock(p->rhs);
	pthread_mutex_lock(p->lhs);
	mutex_print(p, EAT);
	p->eat_cnt++;
	p->last_meal = get_time();
	ft_wait(p->v->eat);
	pthread_mutex_unlock(p->rhs);
	pthread_mutex_unlock(p->lhs);
}

void	*do_philo(void *arg)
{
	pthread_t		monitor;
	t_philosopher	*p;

	p = (t_philosopher *)arg;
	if (pthread_create(&monitor, NULL, &do_monitor, p) != 0)
	{
		printf("thread failed");
		return ((void *)0);
	}
	pthread_detach(monitor);
	if (p->p_id % 2 == 1)
		usleep(200);
	while (*(p->v->someone_is_dead) != 1 && is_full(p) != 1)
	{
		mutex_print(p, THINK);
		eat(p);
		mutex_print(p, SLEEP);
		ft_wait(p->v->sleep);
	}
	return (arg);
}
