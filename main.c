/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:16:08 by knoda             #+#    #+#             */
/*   Updated: 2021/11/28 16:23:37 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>
#include "philosophers.h"

void	print_vars(t_vars v)
{
	printf("num = %d\n", v.num);
	printf("die = %d\n", v.die);
	printf("eat = %d\n", v.eat);
	printf("sleep = %d\n", v.sleep);
	printf("times = %d\n", v.times);
}

void		*do_philo(void *arg)
{
	t_philosopher	*p;
	// long			eat_time;

	p = (t_philosopher *)arg;
	if (p->p_id % 2 == 1)
		ft_wait(1);
	while (1)
	{
		printf("[%ld]think[%d]\n", get_time() - p->v.s_time, p->p_id);
		pthread_mutex_lock(p->rhs);
		// printf("took right[%d]\n", p->p_id);
		pthread_mutex_lock(p->lhs);
		printf("[%ld]eat[%d]\n", get_time() - p->v.s_time, p->p_id);
		ft_wait(p->v.eat);
		pthread_mutex_unlock(p->rhs);
		pthread_mutex_unlock(p->lhs);
		printf("[%ld]sleep[%d]\n", get_time() - p->v.s_time, p->p_id);
		ft_wait(p->v.eat);
	}
	return (arg);
}

pthread_mutex_t	*ft_init_mutex(int num)
{
	pthread_mutex_t *mutex;
	int				i;
	
	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (num + 1));
	if (!mutex)
		return (NULL);
	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&(mutex[i]), NULL);
		i++;
	}
	return (mutex);
}

int	ft_launch_threads(pthread_t *thread, pthread_mutex_t *mutex, t_vars v, t_philosopher *p)
{
	int			i;

	i = 0;
	while (i < v.num)
	{
		p[i].p_id = i;
		p[i].v = v;
		if (i == 0)
			p[i].lhs = &(mutex[v.num - 1]);
		else
			p[i].lhs = &(mutex[i]);
		if (i == v.num - 1)
			p[i].rhs = &(mutex[0]);
		else
			p[i].rhs = &(mutex[i + 1]);
		if (pthread_create(&(thread[i]), NULL, &do_philo, (void *)(&(p[i]))) != 0)
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int		ft_monitor(pthread_t *thread, pthread_mutex_t *mutex, t_vars v)
{
	void		*retval;
	int			i;

	while (1)
	{
		i = 0;
		while (i < v.num)
		{
			pthread_join(thread[i], &retval);
			i++;
		}
	}
	// pthread_detach(thread[i]);
	free(thread);
	free(mutex);
	return (0);
}

int		main(int argc, char **argv)
{
	t_philosopher	*p;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	t_vars			v;

	p = (t_philosopher *)malloc(sizeof(t_philosopher) * (v.num + 1));
	thread = (pthread_t *)malloc(sizeof(pthread_t) * (v.num + 1));
	mutex = ft_init_mutex(v.num);


	if (parse(argc, argv, &v) == -1)
	{
		printf("hint : enter [num] [die] [eat] [sleep] (times)\n");
		return (1);
	}
	print_vars(v);

	// ft_launch_threads(thread, mutex, v, p);
	// ft_monitor(thread, mutex, v);

	return (0);
}

// int	main()
// {
// 	long	start_time;
	
// 	start_time = get_time();
// 	while (1)
// 	{
// 		printf("%ld\n", get_time() - start_time);
// 		ft_wait(500);
// 	}
// 	return (0);
// }