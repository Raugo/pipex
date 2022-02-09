/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:02:45 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/19 12:15:04 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	unsigned char		chr;
	size_t				a;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	a = 0;
	while (a < n)
	{
		if (str[a] == chr)
			return (str + a);
		a++;
	}
	return (0);
}
