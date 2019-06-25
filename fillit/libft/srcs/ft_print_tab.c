/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:55:28 by hlo               #+#    #+#             */
/*   Updated: 2019/01/23 18:03:23 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab(char **arr_ptr)
{
	int split_i;
	int split_j;

	split_i = 0;
	while (arr_ptr[split_i])
	{
		split_j = 0;
		while (arr_ptr[split_i][split_j])
		{
			ft_putstr(&(arr_ptr[split_i][split_j]));
			split_j++;
		}
		ft_putchar('\n');
		split_i++;
	}
}
