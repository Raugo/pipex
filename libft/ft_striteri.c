/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:01:39 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 14:35:06 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		size;
	int		position;
	char	*str;

	if (!s || !f)
		return ;
	position = 0;
	size = ft_strlen((char *)s);
	str = malloc(sizeof(char) * size + 1);
	if (str == 0)
		return ;
	while (s[position] != 0)
	{
		f(position, &s[position]);
		position++;
	}
	str[position] = 0;
}
