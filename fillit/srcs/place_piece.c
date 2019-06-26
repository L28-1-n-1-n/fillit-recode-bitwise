#include "fillit.h"

#include <stdio.h>

int		place_piece(int i, t_p *lstpj, __uint128_t *board, int w)
{
		if (board[0] & ((__uint128_t)(lstpj->value >> (uint64_t)((i / w) * 16 + i % w))))
			return (0);	/* (uint64_t)((i / w) * 16 + i % w) is offset*/

		if (board[1] & ((__uint128_t)(lstpj->value >> (uint64_t)((i / w - 8) * 16 + i % w))))
			return (0);
		//now add the piece onto board[0] and board[1]
		board[0] |= ((__uint128_t)(lstpj->value >> (uint64_t)((i / w) * 16 + i % w)));
		board[1] |= ((__uint128_t)(lstpj->value >> (uint64_t)((i / w - 8) * 16 + i % w)));
		lstpj->pos = i;

		return (1);
	}
