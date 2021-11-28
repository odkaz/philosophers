/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:26:18 by knoda             #+#    #+#             */
/*   Updated: 2021/11/18 13:50:00 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	mallen(int n)
{
	int		len;
	long	ln;

	if (n == 0)
		return (2);
	len = 1;
	ln = (long)n;
	if (ln < 0)
	{
		ln *= -1;
		len++;
	}
	while (ln >= 1)
	{
		ln /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	div;
	long	ln;

	res = (char *)ft_calloc(mallen(n), sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	ln = n;
	div = 1;
	if (ln < 0)
	{
		res[i++] = '-';
		ln *= -1;
	}
	while (ln / div >= 10)
		div *= 10;
	while (div >= 1)
	{
		res[i++] = ln / div + '0';
		ln %= div;
		div /= 10;
	}
	return (res);
}
