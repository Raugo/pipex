/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:37:53 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 14:34:33 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char			*dest;
	unsigned const char		*source;
	size_t					a;

	dest = dst;
	source = src;
	a = 0;
	if (!src && !dst)
		return (0);
	if (dest < source)
	{
		while (a < n)
		{
			dest[a] = source[a];
			a++;
		}
	}
	else
	{
		while (n-- > 0)
			dest[n] = source[n];
	}
	return (dst);
}
