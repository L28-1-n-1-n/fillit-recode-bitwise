/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:02:21 by hlo               #+#    #+#             */
/*   Updated: 2019/01/20 21:06:46 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p;

	while (n--)
	{
		if ((*(unsigned char *)s++) == (unsigned char)c)
		{
			p = (unsigned char *)s - 1;
			return (p);
		}
	}
	return (0);
}
