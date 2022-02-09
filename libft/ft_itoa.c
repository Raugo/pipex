/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:23:26 by josuna-t          #+#    #+#             */
/*   Updated: 2021/11/08 15:00:46 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getlength(long int n)
{
	int	length;

	length = 0;
	while (n / 10 > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char		*strnum;
	int			length;
	int			minus;
	long int	ln;

	ln = n;
	minus = 0;
	if (ln < 0)
	{
		minus = 1;
		ln = -ln;
	}
	length = getlength(ln);
	strnum = ft_calloc(sizeof(char), length + 2 + minus);
	if (strnum == 0)
		return (0);
	if (minus == 1)
		strnum[0] = '-';
	while (length > 0)
	{
		strnum[length-- + minus] = ln % 10 + 48;
		ln = ln / 10;
	}
	strnum[length + minus] = ln % 10 + 48;
	return (strnum);
}
