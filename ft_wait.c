/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:09:08 by knoda             #+#    #+#             */
/*   Updated: 2021/11/28 16:02:01 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_wait(long ms)
{
	long	start_time;

	start_time = get_time();
	while (1)
	{
		if (get_time() - start_time >= ms)
		{
			return ;
		}
		usleep(ms);
	}
}
