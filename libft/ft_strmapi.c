/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:01:39 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 14:35:54 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	int		position;
	char	*str;

	if (!s || !f)
		return (0);
	position = 0;
	size = ft_strlen((char *)s);
	str = malloc(sizeof(char) * size + 1);
	if (str == 0)
		return (0);
	while (s[position] != 0)
	{
		str[position] = f(position, s[position]);
		position++;
	}
	str[position] = 0;
	return (str);
}
