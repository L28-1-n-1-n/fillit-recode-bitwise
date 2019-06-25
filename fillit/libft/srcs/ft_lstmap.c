/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:57:57 by hlo               #+#    #+#             */
/*   Updated: 2019/04/29 14:44:03 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *mod_lst;
	t_list *final_lst;
	t_list *d_lst;

	final_lst = (t_list *)malloc(sizeof(t_list));
	final_lst = NULL;
	d_lst = (t_list *)malloc(sizeof(t_list));
	d_lst = NULL;
	if (lst && f)
	{
		while ((lst) && (lst->content != NULL))
		{
			mod_lst = f(lst);
			if (!(d_lst = ft_lstnew(mod_lst->content, mod_lst->content_size)))
			{
				free(d_lst);
				return (NULL);
			}
			ft_lstappend(&final_lst, d_lst);
			lst = lst->next;
		}
		return (final_lst);
	}
	return (NULL);
}
