#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int		place_piece(int i, t_p *lstpj, __uint128_t *board, int w)
{
		/*testing begins*/
		__uint128_t demo1;
		__uint128_t demo2;
		char *demo_board;
		int k;

		printf("\ni : %d, w: %d, (i / w) * 16 + i mod w : %d\n", i, w, (i / w) * 16 + i % w);
		demo1 = (__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w));
		demo2 = (__uint128_t)(lstpj->value >> ((i / w - 8) * 16 + i % w));
		//printf("lstpj->value is %llu\n", lstpj->value);
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
			if ((demo1 >> k) % 2)
				demo_board[i] = 'X';
			k++;
			i--;
		}

		i = 255;
		k = 0;
		while (i >= 128)
		{
			if ((demo2 >> k) % 2)
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
		/*testing ends*/

		if (board[0] & ((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w))))
			return (0);	/* (uint64_t)((i / w) * 16 + i % w) is offset*/

		if (board[1] & ((__uint128_t)(lstpj->value >> ((i / w - 8) * 16 + i % w))))
			return (0);
		//now add the piece onto board[0] and board[1]
		board[0] |= ((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w)));
		board[1] |= ((__uint128_t)(lstpj->value >> ((i / w - 8) * 16 + i % w)));
		lstpj->pos = i;

		return (1);
}
