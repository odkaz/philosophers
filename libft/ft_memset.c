/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:27:10 by knoda             #+#    #+#             */
/*   Updated: 2021/11/18 13:51:11 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c;

	ptr = (unsigned char *)buf;
	c = (unsigned char)ch;
	while (n--)
		*ptr++ = c;
	return (buf);
}
