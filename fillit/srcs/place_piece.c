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
					printf("\npiece is %d and we consider i : %d \n", lstpj->name[0], i);

					if (board[0] & ((__uint128_t)(lstpj->value >> ((i / w) * 16  + i % w))))
						return (0);	/* (__uint128_t)((i / w) * 16 + i % w) is offset */

					if (board[1] & ((__uint128_t)((lstpj->value << (i / w + lstpj->height - 7) * 16) >> i % w )))
						return (0);

						printf("i: %d, w: %d, (i / w) * 16  + i mod w) : %d\n", i, w, (i / w) * 16  + i % w);
			//			printf("lstpj->value >> ((i / w) * 16  + i mod w) is %llu\n", lstpj->value >> ((i / w) * 16  + i % w));

						board[0] |= ((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w)));

						printf("i: %d, w: %d, (i / w + lstpj->height - 7) * 16 = %d\n", i, w, (i / w + lstpj->height - 7) * 16);
						printf("lstp->value << this number, then >> %d\n", i % w);
				//		printf("lstpj->value << (i / w + lstpj->height - 7) * 16) >> i mod w )is %d\n", (lstpj->value << (i / w + lstpj->height - 7) * 16) >> i % w );

						board[1] |= ((__uint128_t)((lstpj->value << (i / w + lstpj->height - 1- 7) * 16) >> i % w ));
						/*this is the problem. When tetris is between the 2 boards, it is not split up properly*/
						
						__uint128_t demo1;
						int k;
						int q;
						char *demo_board_one;

						demo_board_one = (char *)malloc(sizeof(char) * 128);
						printf("\nNow printing demo_board_one:\n");
						q = 0;
						while (q < 128)
							demo_board_one[q++] = '.';
						demo_board_one[q] = 0;

						demo1 = ((__uint128_t)((lstpj->value << (i / w + lstpj->height - 7 - 1) * 16) >> i % w ));
						q = 255;
						k = 0;
						while (q >= 128)
						{
							if ((demo1>> k) % 2)
								demo_board_one[q] = 'X';
							k++;
							q--;
						}
						q = 0;
						while (q < 128)
						{
							if (q % 16 == 0)
								printf("\n");
							printf("%c ", demo_board_one[q]);
							q++;
						}
						free(demo_board_one);

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
