#include "fillit.h"
#include <stdio.h>

void	unplace_piece(int i, t_p *lstpj, __uint128_t *board, int w)
{
	if ((i / w) > 7)
	{
		board[1] = (board[1] ^ ((__uint128_t)
		(lstpj->value >> ((i / w - 8) * 16 + i % w))));
	}
	else
	{
		if ((i / w) + lstpj->height <= 8)
			{
				board[0] = (board[0] ^ ((__uint128_t)
				(lstpj->value >> ((i / w) * 16 + i % w))));
			}
		else
			{
					board[0] = (board[0] ^ ((__uint128_t)
					(lstpj->value >> ((i / w) * 16 + i % w))));
					board[1] = (board[1] ^ ((__uint128_t)((lstpj->value <<
						(i / w + lstpj->height - 8) * 16) >> i % w )));
			}
	}
	lstpj->pos = 400;
}
