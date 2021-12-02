/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:16:08 by knoda             #+#    #+#             */
/*   Updated: 2021/12/02 14:52:57 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_vars(t_vars *v)
{
	printf("num = %d\n", v->num);
	printf("die = %d\n", v->die);
	printf("eat = %d\n", v->eat);
	printf("sleep = %d\n", v->sleep);
	printf("times = %d\n", v->times);

	printf("someone_is_dead = %d\n", *(v->someone_is_dead));
}

int			is_full(t_philosopher *p)
{
	int		i;
	int		cnt;

	if (p->v->times == -1)
		return (0);
	i = 0;
	cnt = 0;
	while (i < p->v->num)
	{
		if (p->all[i].eat_cnt >= p->v->times)
			cnt++;
		i++;
	}
	if (cnt == p->v->num)
		return (1);
	return (0);
}

void		mutex_print(t_philosopher *p, int msg)
{
	pthread_mutex_lock(p->w_mtx);
	if (*(p->v->someone_is_dead) != 1 && is_full(p) != 1)
	{
		if (msg == EAT)
		{
			printf("[%ld]eat[%d]\n", get_time() - p->v->s_time, p->p_id);
		}
		if (msg == SLEEP)
		{
			printf("[%ld]sleep[%d]\n", get_time() - p->v->s_time, p->p_id);
		}
		if (msg == THINK)
		{
			printf("[%ld]think[%d]\n", get_time() - p->v->s_time, p->p_id);
		}
	}
	if (msg == DEAD && is_full(p) != 1)
	{
		printf("---------[%ld]dead[%d]-----------\n", get_time() - p->v->s_time, p->p_id);
	}
	pthread_mutex_unlock(p->w_mtx);
}

void		*do_monitor(void *arg)
{
	t_philosopher	*p;

	p = (t_philosopher *)arg;
	while (*(p->v->someone_is_dead) != 1)
	{
		if (get_time() - p->last_meal >= p->v->die)
		{
			*(p->v->someone_is_dead) = 1;
			mutex_print(p, DEAD);
		}
		usleep(500);
	}
	return (arg);
}

void		*do_philo(void *arg)
{
	pthread_t		monitor;
	t_philosopher	*p;

	p = (t_philosopher *)arg;
	if (pthread_create(&monitor, NULL, &do_monitor, p) != 0)
	{
		printf("thread failed");
		return ((void *)0);
	}
	// printf("philo[%d] flag = %p, mtx = %p\n", p->p_id, p->v->someone_is_dead, p->w_mtx);
	pthread_detach(monitor);
	if (p->p_id % 2 == 1)
		usleep(200);
	while (*(p->v->someone_is_dead) != 1 && is_full(p) != 1)
	{  
		// printf("[%ld]think[%d]\n", get_time() - p->v->s_time, p->p_id);
		mutex_print(p, THINK);
		pthread_mutex_lock(p->rhs);
		pthread_mutex_lock(p->lhs);
		mutex_print(p, EAT);
		p->eat_cnt++;
		// printf("[%ld]eat[%d]\n", get_time() - p->v->s_time, p->p_id);
		p->last_meal = get_time();
		ft_wait(p->v->eat);
		pthread_mutex_unlock(p->rhs);
		pthread_mutex_unlock(p->lhs);
		mutex_print(p, SLEEP);
		// printf("[%ld]sleep[%d]\n", get_time() - p->v->s_time, p->p_id);
		ft_wait(p->v->sleep);
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
		pthread_mutex_init(mutex + i, NULL);
		i++;
	}
	return (mutex);
}

int	ft_launch_threads(pthread_t *thread, pthread_mutex_t *mutex, t_vars *v, t_philosopher *p)
{
	int			i;
	pthread_mutex_t	w_mutex;

	pthread_mutex_init(&w_mutex, NULL);
	i = 0;
	while (i < v->num)
	{
		p[i].p_id = i;
		p[i].v = v;
		p[i].last_meal = v->s_time;
		p[i].eat_cnt = 0;
		p[i].w_mtx = &w_mutex;
		p[i].all = p;
		if (i == 0)
			p[i].lhs = &(mutex[v->num - 1]);
		else
			p[i].lhs = &(mutex[i - 1]);
		p[i].rhs = mutex + i;
		if (pthread_create(thread + i, NULL, &do_philo, (void *)(p + i)) != 0)
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int		ft_monitor(pthread_t *thread, pthread_mutex_t *mutex, t_vars *v)
{
	void		*retval;
	int			i;

	i = 0;
	while (i < v->num)
	{
		pthread_join(thread[i], &retval);
		i++;
	}
	free(v->someone_is_dead);
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

	if (parse(argc, argv, &v) == -1)
	{
		printf("hint : enter [num] [die] [eat] [sleep] (times)\n");
		return (1);
	}
	p = (t_philosopher *)malloc(sizeof(t_philosopher) * (v.num + 1));
	thread = (pthread_t *)malloc(sizeof(pthread_t) * (v.num + 1));
	mutex = ft_init_mutex(v.num);
	if (!mutex)
	{
		printf("mutex failed\n");
		return (1);
	}

	ft_launch_threads(thread, mutex, &v, p);
	ft_monitor(thread, mutex, &v);

	return (0);
}

// int	main()
// {
// 	long	start_time;
	
// 	start_time = get_time();
// 	while (1)
// 	{
// 		printf("%ld\n", get_time() - start_time);
// 		ft_wait(1000);
// 	}
// 	return (0);
// }