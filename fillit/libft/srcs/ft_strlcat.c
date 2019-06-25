/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:01:53 by hlo               #+#    #+#             */
/*   Updated: 2019/01/19 17:35:43 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlen_excessive(const char *str, long size)
{
	unsigned int n;

	n = 0;
	if (size == -1)
	{
		while (str[n] != '\0')
			n++;
	}
	else
	{
		while (str[n] != '\0' && (long)n < size)
			n++;
	}
	return (n);
}

size_t			ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t length;

	if (ft_strlen_excessive(dest, n) == n)
		return (n + ft_strlen_excessive(src, -1));
	length = ft_strlen_excessive(dest, n) + ft_strlen_excessive(src, -1);
	i = ft_strlen_excessive(dest, n);
	j = 0;
	while (src[j] != '\0' && i < n - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (length);
}
