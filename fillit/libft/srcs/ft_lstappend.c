/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:39:06 by hlo               #+#    #+#             */
/*   Updated: 2019/01/26 19:51:42 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **lst, t_list *elem)
{
	t_list **last;

	last = lst;
	while (*last)
	{
		last = &(*last)->next;
	}
	elem->next = *last;
	*last = elem;
}
