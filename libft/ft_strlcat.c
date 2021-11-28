/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:28:44 by knoda             #+#    #+#             */
/*   Updated: 2020/07/10 22:11:29 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(dst);
	if (len + 1 > size)
	{
		return (size + ft_strlen(src));
	}
	else if (len + 1 < size)
	{
		while (*src && len + 1 < size)
		{
			dst[len++] = *src++;
		}
		dst[len] = '\0';
	}
	return (len + ft_strlen(src));
}
