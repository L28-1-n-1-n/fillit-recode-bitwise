/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 03:49:43 by hlo               #+#    #+#             */
/*   Updated: 2019/01/19 17:41:21 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while ((*haystack != *needle) && (*haystack != '\0'))
		haystack++;
	if (*haystack == '\0')
		return (NULL);
	while ((haystack[i] == needle[i]) && (needle[i] != '\0'))
		i++;
	if (needle[i] == '\0')
		return ((char *)haystack);
	else
		return (ft_strstr(haystack + 1, needle));
}
