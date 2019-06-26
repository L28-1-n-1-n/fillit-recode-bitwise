#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int		place_piece(int i, t_p *lstpj, __uint128_t *board, int w)
{
		if ((i / w) > 7) /* i.e. 8 or above, case when it only affects board[1]*/
		{
			if (board[1] & ((__uint128_t)(lstpj->value >> ((i / w - 8) * 16 + i % w))))
				return (0);
			board[1] |= ((__uint128_t)(lstpj->value >> ((i / w - 8) * 16 + i % w)));
		}
		else
		{
			if ((i / w) + lstpj->height <= 8) //Essentially (i/w + height - 1 <= 7), meaning last line of piece falls within 128, or board[0]
				{
					if (board[0] & ((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w))))
						return (0);	/* (__uint128_t)((i / w) * 16 + i % w) is offset*/
					board[0] |= ((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w)));
				}
			else // case where piece needs to be split
				{
					if (board[0] & ((__uint128_t)(lstpj->value >> ((i / w) * 16  + i % w))))
						return (0);	/* (__uint128_t)((i / w) * 16 + i % w) is offset */

					if (board[1] & ((__uint128_t)((lstpj->value << (i / w + lstpj->height - 7) * 16) >> i % w )))
						return (0);

						board[0] |= ((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w)));
						board[1] |= ((__uint128_t)((lstpj->value << (i / w + lstpj->height - 7) * 16) >> i % w ));
				}
		}
		lstpj->pos = i;

		/*testing begins

		char *demo_board;
		int k;

		demo_board = (char *)malloc(sizeof(char) * 256);
		printf("\nNow printing demo_board:\n");
		i = 0;
		while (i < 256)
			demo_board[i++] = '.';
		demo_board[i] = 0;

		i = 127;
		k = 0;
		while (i >= 0)
		{
			if ((board[0] >> k) % 2)
				demo_board[i] = 'X';
			k++;
			i--;
		}

		i = 255;
		k = 0;
		while (i >= 128)
		{
			if ((board[1]>> k) % 2)
				demo_board[i] = 'X';
			k++;
			i--;
		}

		i = 0;
		while (i < 256)
		{
			if (i % 16 == 0)
				printf("\n");
			printf("%c ", demo_board[i]);
			i++;
		}
		free(demo_board);
		testing ends*/

		return (1);
}
/*
		if (board[0] & ((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w))))
			return (0);

		if (board[1] & ((__uint128_t)(lstpj->value >> ((i / w - 8) * 16 + i % w))))
			return (0);
		//now add the piece onto board[0] and board[1]
		board[0] |= ((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w)));
		board[1] |= ((__uint128_t)(lstpj->value >> ((i / w - 8) * 16 + i % w)));
*/
