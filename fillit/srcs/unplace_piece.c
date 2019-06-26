#include "fillit.h"
#include <stdio.h>

void	unplace_piece(int i, t_p *lstpj, __uint128_t *board, int w)
{
	if ((i / w) > 7) /* i.e. 8 or above, case when it only affects board[1]*/
	{
		board[1] = (board[1] ^ ((__uint128_t)(lstpj->value >> ((i / w - 8) * 16 + i % w))));
	}
	else
	{
		if ((i / w) + lstpj->height <= 8) //Essentially (i/w + height - 1 <= 7), meaning last line of piece falls within 128, or board[0]
			{
				board[0] = (board[0] ^ ((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w))));
			}
		else // case where piece needs to be split
			{
					board[0] = (board[0] ^ ((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w))));
					board[1] = (board[1] ^ ((__uint128_t)((lstpj->value << (i / w + lstpj->height - 7) * 16) >> i % w )));
			}
	}
	lstpj->pos = 400;
}

/*
board[0] = (board[0] ^ ((__uint128_t)(lstpj->value >> (uint64_t)((i / w) * 16 + i % w))));
board[1] = (board[1] ^ ((__uint128_t)(lstpj->value >> (uint64_t)((i / w - 8) * 16 + i % w))));
lstpj->pos = 400;
*/
