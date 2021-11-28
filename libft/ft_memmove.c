/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:27:03 by knoda             #+#    #+#             */
/*   Updated: 2021/11/18 13:51:02 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)buf1;
	str2 = (unsigned char *)buf2;
	if (str1 < str2)
		ft_memcpy(buf1, buf2, n);
	else if (str1 > str2)
		while (n--)
			str1[n] = str2[n];
	return (buf1);
}
