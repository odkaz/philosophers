/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:29:17 by knoda             #+#    #+#             */
/*   Updated: 2021/11/18 13:53:09 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char *)big);
	while (*big && len >= ft_strlen(little))
	{
		if (ft_strncmp(big, little, ft_strlen(little)) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
