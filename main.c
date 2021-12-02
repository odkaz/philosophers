/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:16:08 by knoda             #+#    #+#             */
/*   Updated: 2021/12/02 15:40:25 by knoda            ###   ########.fr       */
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

pthread_mutex_t	*init_mutex(int num)
{
	pthread_mutex_t	*mutex;
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

int	monitor(t_philosopher *p, pthread_t *thread, pthread_mutex_t *mutex, t_vars *v)
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
	free(p);
	free(thread);
	free(mutex);
	return (0);
}

int	main(int argc, char **argv)
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
	if (!p || !thread)
		return (1);
	mutex = init_mutex(v.num);
	if (!mutex)
		return (1);
	launch_threads(thread, mutex, &v, p);
	monitor(p, thread, mutex, &v);
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