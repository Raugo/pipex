/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:30:02 by josuna-t          #+#    #+#             */
/*   Updated: 2021/11/06 13:28:15 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int	*arr;
	int	total;

	if (size * count == 0)
		total = 1;
	else
		total = size * count;
	arr = malloc(total);
	if (arr == 0)
		return (0);
	ft_memset(arr, 0, total);
	return (arr);
}
