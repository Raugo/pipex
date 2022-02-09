/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:08:06 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 14:37:26 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	srcsize;

	if (!s)
		return (0);
	srcsize = ft_strlen(s);
	if (srcsize > start)
	{
		if (srcsize < len)
			len = srcsize;
		newstr = ft_calloc (sizeof(char), len + 1);
		if (newstr == 0)
			return (0);
		s = s + start;
		ft_strlcpy(newstr, s, len + 1);
		return (newstr);
	}
	newstr = ft_calloc (sizeof(char), 1);
	if (newstr == 0)
		return (0);
	newstr[0] = 0;
	return (newstr);
}
