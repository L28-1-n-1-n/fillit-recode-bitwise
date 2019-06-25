/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:05:41 by hlo               #+#    #+#             */
/*   Updated: 2019/01/19 17:47:11 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (str[i])
	{
		if (str[i] == (char)c)
			j = i;
		i++;
	}
	if (str[i] == (char)c)
		j = i;
	if (j == -1)
		return (NULL);
	return ((char*)&str[j]);
}
