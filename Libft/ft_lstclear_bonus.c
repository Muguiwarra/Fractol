/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:49:20 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/26 21:55:59 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*p;

	if (lst && del)
	{
		while ((*lst))
		{
			p = (*lst)->next;
			ft_lstdelone((*lst), del);
			*lst = p;
		}
		lst = NULL;
	}
}
