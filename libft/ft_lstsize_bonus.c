/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:26:26 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 14:34:17 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		index;
	t_list	*tempt_list;

	index = 0;
	tempt_list = lst;
	while (tempt_list)
	{
		tempt_list = tempt_list->next;
		index++;
	}
	return (index);
}
