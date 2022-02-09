/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:17:57 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 14:37:53 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*trimcopy(char const *s1, int tsize)
{
	char	*newstr;

	newstr = malloc(sizeof(char) * tsize + 1);
	if (newstr == 0)
		return (0);
	ft_strlcpy(newstr, s1, tsize + 1);
	return (newstr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	cnt;
	size_t	tsize;

	if (!s1 || !set)
		return (0);
	cnt = 0;
	tsize = ft_strlen((char *)s1);
	while (set[cnt] != 0 && *s1 != 0 && tsize > 0)
	{
		if ((*s1 == set[cnt++] || s1[tsize - 1] == set[cnt - 1]) && tsize > 0)
		{
			if (s1[tsize - 1] == set[cnt - 1])
				tsize--;
			if (*s1 == set[cnt - 1] && tsize > 0)
			{
				s1++;
				tsize--;
			}
			cnt = 0;
		}
	}
	return (trimcopy(s1, tsize));
}
