/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:06:22 by hlo               #+#    #+#             */
/*   Updated: 2019/05/03 20:09:12 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	total_len;
	size_t	new_len;
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	if (!s)
		return (0);
	total_len = ft_strlen(s);
	j = total_len - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		&& (i < total_len / 2 + 1))
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		&& (j > total_len / 2 + 1))
		j--;
	if ((i == total_len / 2 + 1) && (j == total_len / 2 + 1))
		new_len = 0;
	else
		new_len = j - i + 1;
	if (!(new_str = ft_strnew(new_len)))
		return (0);
	ft_memcpy(new_str, s + i, new_len);
	return (new_str);
}
