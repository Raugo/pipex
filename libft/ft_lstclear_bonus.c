/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:54:55 by josuna-t          #+#    #+#             */
/*   Updated: 2022/01/18 15:30:13 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tempt_list;

	tempt_list = *lst;
	while (*lst)
	{
		del((*lst)->content);
		tempt_list = *lst;
		*lst = (*lst)->next;
		free (tempt_list);
	}
	lst = 0;
}
