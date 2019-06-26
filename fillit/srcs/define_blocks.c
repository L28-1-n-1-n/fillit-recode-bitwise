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
	i = 1;
	while (lstpj->name[i])
	{
		lstpj->value = lstpj->value + ((lstpj->name[i]) << ( 64 - 16 * i + 12));
		printf("%d zeros added after %d\n",64 - 16 * i + 12, lstpj->name[i]);
		i++;
	}
	printf("Block value of %d is %llu\n", lstpj->name[0], lstpj->value);
/*problem: the above needs to be separated out, since this is read block by block,
at the time of reading we still have no idea how many blocks there are in total,
therefore cannot define lstpj->value since beginning boardsize is not known yet.
Better separate this out as a function after boardsize is defined, like that the function
can be called every time boardsize has changed*/

/*Or, value constant at taille 16, but i only loops through 0 to < w * w
and put safety mask beyond w */

	return (1);
}
