/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:05:51 by hlo               #+#    #+#             */
/*   Updated: 2019/01/24 23:43:20 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordcount(char const *s, char c)
{
	size_t i;
	size_t word_count;

	i = 0;
	word_count = 0;
	if (s)
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i])
				word_count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word_count);
}

static size_t	ft_alpha_per_word(const char *s, char c)
{
	size_t j;

	j = 0;
	while ((s[j]) && (s[j] != c))
		j++;
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	tab;
	size_t	num;
	int		i;

	arr = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (arr && ft_wordcount(s, c))
	{
		i = 0;
		tab = 0;
		while ((s) && (tab < ft_wordcount(s, c)) && (s[i]))
		{
			while (s[i] && s[i] == c)
				i++;
			num = ft_alpha_per_word((char *)(s + i), c);
			if (!(arr[tab] = ft_strnew(ft_alpha_per_word((char *)(s + i), c))))
				return (0);
			ft_strncpy(arr[tab++], &s[i], num);
			while (s[i] && s[i] != c)
				i++;
		}
		arr[tab] = 0;
	}
	return (arr);
}
