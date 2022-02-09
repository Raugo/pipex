/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:12:38 by josuna-t          #+#    #+#             */
/*   Updated: 2021/11/09 16:15:57 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		a;
	char	*str;

	str = (char *)s;
	a = 0;
	while (s[a] != 0)
	{
		if (s[a] == (const char)c)
			return (str + a);
		a++;
	}
	if (s[a] == c)
		return (str + a);
	return (0);
}
