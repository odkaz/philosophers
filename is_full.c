/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_full.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:05:42 by knoda             #+#    #+#             */
/*   Updated: 2021/12/02 15:08:13 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_full(t_philosopher *p)
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
