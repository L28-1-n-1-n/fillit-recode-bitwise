#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

void	gen_board(__uint128_t *board, int w)
{
	int i;
	char *tmp_board;
	__uint128_t k;

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

/*testing begins*/

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

		/*testing ends*/
		
}
	/*actually dont bother limiting the 1111 to width + 1, just go ahead and block
	out the whole row below the desired width*/

//	board[0] = board[0] + ((65535 >> (16 - w - 1)) << (128 - 16 * (w + 1) + (16 - w -1)));
	/*This is essentially equal to 1111111111111111 >> (16 - w - 1), then << (128 - 16 * w) */
	/*This is equal to creating bottom row of 1s, with (w + 1) no of 1s*/



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
*/

/*
	while (i < 16)
	{
		printf("board[i] has value %d\n", board[i]);
		i++;
	}
*/
