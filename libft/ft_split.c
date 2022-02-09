/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:52:43 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/20 15:56:03 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"

int	clean_malloc(char **str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		free(str[count]);
		count++;
	}
	return (-1);
}

int	ctwords(char const *s, char c, int *maxlength)
{
	int		ct;
	int		words;
	int		oldlength;

	*maxlength = 0;
	ct = 0;
	words = 0;
	while (s[ct] == c)
		ct++;
	while (s[ct] != 0)
	{
		if (s[ct] == c && s[ct + 1] != c && s[ct + 1] != 0)
		{
			words++;
			if (*maxlength < ct - oldlength)
				*maxlength = ct - oldlength;
			oldlength = ct;
		}
		ct++;
	}
	if (words == 0)
		*maxlength = (int)ft_strlen((char *)s);
	return (words);
}

int	findnextword(char const *s, char c, int maxlength, char **arr)
{
	size_t	pst;
	size_t	oldpst;
	int		words;

	words = 0;
	pst = 0;
	while (s[pst] != 0)
	{
		while (s[pst] == c)
			pst++;
		oldpst = pst;
		while (s[pst] != c && s[pst] != 0)
			if (s[pst] != 0)
				pst++;
		if (oldpst != pst)
		{
			arr[words] = malloc(sizeof(char) * (maxlength + 2));
			if (!(arr[words]))
				return (clean_malloc(arr));
			ft_strlcpy(arr[words++], s + oldpst, pst - oldpst + 1);
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	int		maxlength;

	if (!s)
		return (0);
	words = ctwords(s, c, &maxlength);
	arr = malloc(sizeof(char *) * (words + 2));
	if (!(arr))
		return (0);
	words = findnextword(s, c, maxlength, arr);
	if (words == -1)
		return (0);
	arr[words] = 0;
	return (arr);
}
