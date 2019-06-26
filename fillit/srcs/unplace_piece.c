#include "fillit.h"
#include <stdio.h>

void	unplace_piece(int i, t_p *lstpj, __uint128_t *board, int w)
{
	board[0] = (board[0] ^ ((__uint128_t)(lstpj->value >> (uint64_t)((i / w) * 16 + i % w))));
	board[1] = (board[1] ^ ((__uint128_t)(lstpj->value >> (uint64_t)((i / w - 8) * 16 + i % w))));
	lstpj->pos = 400;
}
