#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int		place_piece(int i, t_p *lstpj, __uint128_t *board, int w)
{
		if ((i / w) > 7)
		{
			if (board[1] & ((__uint128_t)(lstpj->value >> ((i / w - 8) * 16 + i % w))))
				return (0);
			board[1] |= ((__uint128_t)(lstpj->value >> ((i / w - 8) * 16 + i % w)));
		}
		else
		{
			if ((i / w) + lstpj->height <= 8)
				{
					if (board[0] & ((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w))))
						return (0);
					board[0] |= ((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w)));
				}
			else
				{
					if (board[0] & ((__uint128_t)(lstpj->value >> ((i / w) * 16  + i % w))))
						return (0);
					if (board[1] & ((__uint128_t)((lstpj->value << (i / w + lstpj->height - 8) * 16) >> i % w )))
						return (0);
						board[0] |= ((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w)));
						board[1] |= ((__uint128_t)((lstpj->value << (i / w + lstpj->height - 1- 8) * 16) >> i % w ));
				}
		}
		lstpj->pos = i;
		return (1);
}
