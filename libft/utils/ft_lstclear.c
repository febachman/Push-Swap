/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:41:36 by fbachman          #+#    #+#             */
/*   Updated: 2026/05/26 14:11:42 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*following;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		following = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = following;
	}
}
