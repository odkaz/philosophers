/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:28:53 by knoda             #+#    #+#             */
/*   Updated: 2021/11/18 13:52:25 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*d;
	char	*s;

	d = dest;
	s = (char *)src;
	if (!size)
		return (ft_strlen(src));
	while (d != NULL && *s && --size)
		*d++ = *s++;
	*d = '\0';
	return (ft_strlen(src));
}
