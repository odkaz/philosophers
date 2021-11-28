/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:28:16 by knoda             #+#    #+#             */
/*   Updated: 2021/11/18 13:51:55 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;

	res = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, ft_strlen(s) + 1);
	return (res);
}
