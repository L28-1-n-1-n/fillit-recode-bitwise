/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:02:13 by hlo               #+#    #+#             */
/*   Updated: 2019/01/20 18:19:38 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			while (s[i] && i < len)
			{
				new_str[i] = f(s[i]);
				i++;
			}
			new_str[i] = '\0';
			return (new_str);
		}
	}
	return (NULL);
}
