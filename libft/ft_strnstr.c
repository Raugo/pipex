/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:43:36 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 14:36:03 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (to_find[0] == 0)
		return ((char *)str);
	while (str[a] != 0 && a <= len)
	{
		b = 0;
		while (str[a + b] == to_find[b] && (a + b <= len - 1))
		{
			b++;
			if (to_find[b] == 0)
				return ((char *)str + a);
		}
		a++;
	}
	return (0);
}
