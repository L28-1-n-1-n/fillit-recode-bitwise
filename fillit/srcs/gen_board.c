#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

void	gen_board(__uint128_t *board, int w)
{
	int i;

	board[0] = (__uint128_t)0;
	board[1] = (__uint128_t)0;

	i = 1;
	if (w < 8)
	{
		while (i <= w)  /*create right border just until before w + 1*/
		{
			board[0] = board[0] + ((__uint128_t)1 << (128 - 16 * i + (16 - w - 1)));
			i++;
		}
		board[0] = board[0] + ((__uint128_t)65535 << ((8 - w -1) * 16));
	}
	else //case when w = 8 or above, involve board[1];
		{
			while (i <= 8)  /*create right border just until before w + 1*/
			{
				board[0] = board[0] + ((__uint128_t)1 << (128 - 16 * i + (16 - w - 1)));
				i++;
			}
			while (i <= w)  /*create right border just until before w*/
			{
				board[1] = board[1] + ((__uint128_t)1 << (128 - 16 * (i - 8) + (16 - w - 1)));
				i++;
			}
			board[1] = board[1] + ((__uint128_t)65535 << ((16 - w - 1)) * 16);
		}

/* To print the border*/
/*
		char *tmp_board;
		__uint128_t k;
		tmp_board = (char *)malloc(sizeof(char) * 256);
		i = 0;
		while (i < 256)
			tmp_board[i++] = '.';
		tmp_board[i] = 0;

		i = 127;
		k = 0;
		while (i >= 0)
		{
			if ((board[0] >> k) % 2)
				tmp_board[i] = 'X';
			k++;
			i--;
		}

		i = 255;
		k = 0;
		while (i >= 128)
		{
			if ((board[1] >> k) % 2)
				tmp_board[i] = 'X';
			k++;
			i--;
		}

		i = 0;
		while (i < 256)
		{
			if (i % 16 == 0)
				printf("\n");
			printf("%c ", tmp_board[i]);
			i++;
		}
		free(tmp_board);
*/
		/* End of printing border*/

}

/*
Boundary for w of 2 is
0010 i = 1, padding zeros
0010
0000
0000

PLUS

0000
0000
1110
0000

which gives:
00X0
00X0
XXX0
0000
*/
