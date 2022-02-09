/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:13:11 by josuna-t          #+#    #+#             */
/*   Updated: 2021/11/06 13:27:36 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		a;
	int		c;
	char	*copy;

	c = 0;
	a = ft_strlen((char *)src) + 1;
	copy = malloc(a);
	if (copy == 0)
		return (0);
	while (src[c] != 0)
	{
		copy[c] = src[c];
		c++;
	}
	copy[c] = 0;
	return (copy);
}
