/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:25:53 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 14:34:25 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		a;
	const unsigned char	*str;
	const unsigned char	*str2;

	str = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	a = 0;
	while (a < n)
	{
		if (str[a] != str2[a])
			return (str[a] - str2[a]);
		a++;
	}
	if (a == n)
		return (0);
	return (str[a] - str2[a]);
}
