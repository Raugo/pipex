/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:12:38 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 14:37:21 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		a;
	char	*str;

	str = (char *)s;
	a = ft_strlen(str);
	while (a >= 0)
	{
		if (s[a] == (const char)c)
			return (str + a);
		a--;
	}
	return (0);
}
