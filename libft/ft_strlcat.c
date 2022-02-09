/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:36:55 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 14:35:14 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	count;
	unsigned int	tsize;

	count = 0;
	while (dest[count] != 0 & count <= size)
		count++;
	tsize = size - count;
	if (count < size)
		return (count + ft_strlcpy(dest + count, src, tsize));
	return (ft_strlen((char *)src) + size);
}
