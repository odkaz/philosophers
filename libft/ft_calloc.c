/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:25:06 by knoda             #+#    #+#             */
/*   Updated: 2021/11/18 14:04:00 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;

	res = (void *)malloc(size * n);
	if (res)
		ft_bzero(res, size * n);
	else
		exit(1);
	return (res);
}
