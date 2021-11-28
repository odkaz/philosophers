/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:27:58 by knoda             #+#    #+#             */
/*   Updated: 2021/11/18 14:01:59 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_mal(char const *s, char c)
{
	int	cnt;
	int	flag;

	cnt = 1;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		flag = 0;
		while (*s != c && *s)
		{
			flag = 1;
			s++;
		}
		if (flag)
			cnt++;
	}
	return (cnt);
}

static void	*free_all(char **res, int index)
{
	while (index--)
		free(res[index]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		index;
	int		i;

	res = (char **)ft_calloc(cnt_mal(s, c), sizeof(char *));
	index = 0;
	while (*s)
	{
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i > 0)
		{
			res[index] = ft_substr(s, 0, i);
			if (!res[index])
				return (free_all(res, index));
			index++;
			s += i;
		}
		while (*s == c && *s)
			s++;
	}
	res[index] = NULL;
	return (res);
}
