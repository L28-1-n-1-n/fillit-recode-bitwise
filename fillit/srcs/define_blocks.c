/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_blocks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:10:32 by hlo               #+#    #+#             */
/*   Updated: 2019/05/04 19:10:45 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int define_blocks(char *o_arr, t_p *lstpj)
{
	int i;

	i = 0;
  if (o_arr == ER) /*ER block assigned for invalid block*/
		return (ERROR);
	while (i < 6)
	{
		lstpj->name[i] = o_arr[i] - 'E';
		i++;
	}

	i = 1; /*starts from the first position that codes for block shape*/
	while (lstpj->name[i])
	{
		lstpj->value |= ((__uint128_t)(lstpj->name[i]) << ( 128 - 16 * i + 12));
		i++;
	}
	lstpj->height = i - 1;

	//printf("i is %d and lstpj->height is %d\n", i, lstpj->height);

	return (1);
}
