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

int define_blocks(char *o_arr, t_p *lstpj, int w)
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
	while (o_arr[i] != 'E')
	{
		lstpj->value = lstpj->value + ((o_arr[i] - 'E') << ( w * w - w * i + w - 4))
		i++;
	}

/*problem: the above needs to be separated out, since this is read block by block,
at the time of reading we still have no idea how many blocks there are in total,
therefore cannot define lstpj->value since beginning boardsize is not known yet.
Better separate this out as a function after boardsize is defined, like that the function
can be called every time boardsize has changed*/

	return (1);
}
