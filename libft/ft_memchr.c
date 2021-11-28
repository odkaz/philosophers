/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:26:39 by knoda             #+#    #+#             */
/*   Updated: 2021/11/18 13:50:28 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	unsigned char	*s;
	unsigned char	c;

	s = (unsigned char *)buf;
	c = (unsigned char)ch;
	while (n--)
	{
		if (*s == (unsigned char)c)
			return (s);
		s++;
	}
	return (NULL);
}
