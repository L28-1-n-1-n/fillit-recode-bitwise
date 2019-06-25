/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 03:49:43 by hlo               #+#    #+#             */
/*   Updated: 2019/01/19 18:15:01 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndle, size_t len)
{
	size_t i;

	i = 0;
	if (!ndle[0])
		return ((char *)hay);
	while (hay[i] && i + ft_strlen(ndle) <= len)
	{
		if ((ft_strncmp(&hay[i], ndle, ft_strlen(ndle))) == 0)
			return ((char*)&hay[i]);
		i++;
	}
	return (NULL);
}
