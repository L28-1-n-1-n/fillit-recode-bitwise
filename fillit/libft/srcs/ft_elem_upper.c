/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_upper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:52:16 by hlo               #+#    #+#             */
/*   Updated: 2019/01/26 22:35:51 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_elem_upper(t_list *elem)
{
	t_list			*upper_lst;
	char			*to_change;
	unsigned int	after_len;

	if (!(to_change = malloc(sizeof(elem->content) * (elem->content_size))))
	{
		free(to_change);
		return (NULL);
	}
	ft_memcpy(to_change, (const void *)(elem->content), elem->content_size);
	after_len = ft_strlen(to_change);
	while (*to_change)
	{
		*to_change = ft_char_toupper(*to_change);
		to_change++;
	}
	if (!(upper_lst = ft_lstnew(to_change - after_len, elem->content_size)))
	{
		return (NULL);
		free(upper_lst);
	}
	return (upper_lst);
}
