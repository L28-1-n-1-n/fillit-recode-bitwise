#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>
void  gen_upperboard(__uint128_t *board, int w, int i)
{
	while (i <= 8)
	{
		board[0] += ((__uint128_t)1 << (128 - 16 * i + (16 - w - 1)));
		i++;
	}
	while (i <= w)
	{
		board[1] += ((__uint128_t)1 <<
		(128 - 16 * (i - 8) + (16 - w - 1)));
		i++;
	}
	board[1] += ((__uint128_t)65535 << ((16 - w - 1)) * 16);
}
void	gen_board(__uint128_t *board, int w)
{
	int i;

	board[0] = (__uint128_t)0;
	board[1] = (__uint128_t)0;
	i = 1;
	if (w < 8)
	{
		while (i <= w)
		{
			board[0] += ((__uint128_t)1 << (128 - 16 * i + (16 - w - 1)));
			i++;
		}
		board[0] += ((__uint128_t)65535 << ((8 - w -1) * 16));
	}
	else
			gen_upperboard(board, w, i);
}
