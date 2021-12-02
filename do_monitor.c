/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:21 by knoda             #+#    #+#             */
/*   Updated: 2021/12/02 15:07:33 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*do_monitor(void *arg)
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
