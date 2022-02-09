/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:11:46 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 14:35:09 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tsize;
	char	*newstr;

	if (!s1)
		return (0);
	tsize = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	newstr = ft_calloc(sizeof(char), tsize);
	if (!newstr)
		return (0);
	ft_strlcpy(newstr, s1, tsize);
	ft_strlcat(newstr, s2, tsize);
	return (newstr);
}
