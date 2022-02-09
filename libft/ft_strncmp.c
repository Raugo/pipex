/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:25:53 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 17:58:35 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;
	unsigned char	c1;
	unsigned char	c2;

	a = 0;
	while ((s1[a] != 0 && s2[a] != 0) && a < n)
	{
		c1 = (unsigned char)s1[a];
		c2 = (unsigned char)s2[a];
		if (c1 != c2)
			return (c1 - c2);
		a++;
	}
	if (a == n)
		return (0);
	c1 = (unsigned char)s1[a];
	c2 = (unsigned char)s2[a];
	return (c1 - c2);
}
