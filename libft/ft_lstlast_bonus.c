/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:26:26 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 14:34:03 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tempt_list;

	tempt_list = lst;
	while (tempt_list)
	{
		if (tempt_list->next)
		{
			tempt_list = tempt_list->next;
		}
		else
			return (tempt_list);
	}
	return (tempt_list);
}
