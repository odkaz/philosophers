/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:06:17 by knoda             #+#    #+#             */
/*   Updated: 2021/12/02 15:11:24 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mutex_print(t_philosopher *p, int msg)
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
		printf("[%ld]dead[%d]\n", get_time() - p->v->s_time, p->p_id);
	}
	pthread_mutex_unlock(p->w_mtx);
}
