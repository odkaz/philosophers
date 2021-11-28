/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:29:48 by knoda             #+#    #+#             */
/*   Updated: 2021/11/18 13:54:56 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (ft_strlen(s) < start)
	{
		res = (char *)ft_calloc(1, sizeof(char));
		if (!res)
			return (NULL);
		return (res);
	}
	res = (char *)ft_calloc((len + 1), sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *)(s + start), (len + 1));
	return (res);
}
