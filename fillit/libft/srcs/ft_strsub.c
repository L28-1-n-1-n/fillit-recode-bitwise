/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:06:08 by hlo               #+#    #+#             */
/*   Updated: 2019/01/19 17:42:44 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	i;
	unsigned int	total_len;

	i = 0;
	if (!s)
		return (NULL);
	new_str = ft_strnew(len);
	total_len = ft_strlen((char *)s);
	if (new_str && ((start + len) <= total_len))
	{
		while (i < len)
		{
			new_str[i] = s[start + i];
			i++;
		}
		return (new_str);
	}
	return (NULL);
}
