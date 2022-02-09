/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:45:24 by josuna-t          #+#    #+#             */
/*   Updated: 2021/11/09 15:05:15 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int						minuscount;
	unsigned long long int	number;
	int						a;

	number = 0;
	a = 0;
	minuscount = 0;
	while (str[a] == ' ' || str[a] == '\t' || str[a] == '\n' || str[a] == '\v'
		|| str[a] == '\f' || str[a] == '\r' )
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			minuscount++;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
		number = number * 10 + str[a++] - 48;
	if (number > (unsigned long int)2147483647 + minuscount)
		number = -1 + minuscount;
	if (minuscount % 2 > 0)
		return (-number);
	return (number);
}
