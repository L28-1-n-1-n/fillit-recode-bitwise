/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:54:39 by hlo               #+#    #+#             */
/*   Updated: 2019/01/20 17:50:19 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	index;

	if (src < dest && src + len > dest)
	{
		while (len-- > 0)
			((char*)dest)[len] = ((char*)src)[len];
	}
	else
	{
		index = 0;
		while (index < len)
		{
			((char*)dest)[index] = ((char*)src)[index];
			index++;
		}
	}
	return (dest);
}
