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

char *id_tetri_extend(int *arr)
{
	if ((arr[1] == 1) && (arr[2] == 2))
	{
		if (arr[3] == 3)
			return (H);
		if (arr[3] == 5)
			return (RU);
		if (arr[3] == 6)
			return (TD);
		if (arr[3] == 7)
			return (LD);
	}
	if (arr[1] == 5)
	{
		if ((arr[2] == 6) && (arr[3] == 7))
			return (LU);
		if ((arr[2] == 6) && (arr[3] == 10))
			return (TL);
		if ((arr[2] == 6) && (arr[3] == 11))
			return (ZD);
		if ((arr[2] == 9) && (arr[3] == 10))
			return (LL);
		if ((arr[2] == 10) && (arr[3] == 11))
			return (RL);
		if ((arr[2] == 10) && (arr[3] == 15))
			return (D);
	}
	return (ER);
}

char *id_tetri(int *arr)
{
	if ((arr[1] == 1) && (arr[2] == 4) && (arr[3] == 5))
		return (ZR);
	if ((arr[1] == 1) && (arr[2] == 6) && (arr[3] == 7))
		return (ZL);
	if ((arr[1] == 1) && (arr[2] == 6) && (arr[3] == 11))
		return (RR);
	if ((arr[1] == 1) && (arr[2] == 5) && (arr[3] == 6))
		return (S);
	if ((arr[1] == 1) && (arr[2] == 5) && (arr[3] == 10))
		return (LR);
	if ((arr[1] == 3) && (arr[2] == 4) && (arr[3] == 5))
		return (RD);
	if ((arr[1] == 4) && (arr[2] == 5))
	{
		if (arr[3] == 6)
			return (TU);
		if (arr[3] == 10)
			return (TR);
		if (arr[3] == 9)
			return (ZU);
	}
	return (id_tetri_extend(arr));
}

int  tetri_offset(int *arr, t_p *lstpj)
{
	int	tmp;
	int i;

	i = 0;
	tmp = arr[0];
	while (i < 4)
	{
		arr[i] = arr[i] - tmp;
		i++;
	}
	return (define_blocks(id_tetri(arr), lstpj));
}
