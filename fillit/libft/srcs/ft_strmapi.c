/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:02:20 by hlo               #+#    #+#             */
/*   Updated: 2019/01/20 18:20:27 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	len;
	size_t	i;

	i = 0;
	if (s && f)
	{
		len = ft_strlen((char *)s);
		new_str = ft_strnew(len);
		if (new_str)
		{
			while (s && i < len && s[i])
			{
				new_str[i] = f((unsigned int)i, s[i]);
				i++;
			}
			new_str[i] = '\0';
			return (new_str);
		}
	}
	return (0);
}
