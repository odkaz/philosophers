/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:45:58 by knoda             #+#    #+#             */
/*   Updated: 2021/11/28 16:24:13 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		check_argv(char **argv)
{
	int		i;

	argv++;
	while (*argv)
	{
		i = 0;
		if (!(*argv)[0])
			return (-1);
		while ((*argv)[i])
		{
			if (!ft_isdigit((*argv)[i]))
				return (-1);
			i++;
		}
		argv++;
	}
	return (0);
}

int	parse(int argc, char **argv, t_vars *v)
{
	if (check_argv(argv) == -1)
		return (-1);
	if (argc != 5 && argc != 6)
		return (-1);
	v->num = ft_atoi(argv[1]);
	v->die = ft_atoi(argv[2]);
	v->eat = ft_atoi(argv[3]);
	v->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		v->times = ft_atoi(argv[5]);
	else
		v->times = -1;	
	v->s_time = get_time();
	return (0);
}
