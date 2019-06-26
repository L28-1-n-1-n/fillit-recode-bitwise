#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int solveboard(t_p *lstpj, __uint128_t *board, int *arr, int boardsize, t_p *lstp)
{
		int i;
//		int k;

		i = 0;
		if (lstpj->name[0] == 20)
		{
			arr[0] = -1;
			return (1);
		}
		if (arr[0] == -1)
			return (1);
		printf("before placepiece, this piece is %d\n", lstpj->name[0]);
		while ((arr[0] != -1) && (lstpj->name[0] != 20) && (i < boardsize * boardsize))
		{
					if(place_piece(i, lstpj, board, boardsize))
					{
						printf("place_piece passed with i: %d\n", i);

					/*	k = 0;
						while (k <= boardsize)
						{
							printf("board[%d] has value %d\n", k, board[k]);
							k++;
						}*/
						printf("\nhola\n");
						print_board(lstp, boardsize);

						lstpj += 1;
						printf("the next piece is %d\n", lstpj->name[0]);
						if (solveboard(lstpj, board, arr, boardsize, lstp))
						{
							printf("pass to solveboard, lstpj++ : %d", lstpj->name[0]);
							return (1);
						}
						else
						{
							lstpj = lstpj - 1;
							printf("about to unplace istpj : %d", lstpj->name[0]);
							unplace_piece(i, lstpj, board, boardsize);
							printf("after unplace, lstpj is now %d\n", lstpj->name[0]);
			//				print_board(lstp, boardsize);
							i++;
						}
/*	unplace piece; using XOR gate: a ^ b (a XOR b) -> all 1 and 1 become zero, so used ^ this piece = undo this piece */
					}
					else
					{
						printf("placepiec rejected - i: %d, lstpj: %d\n\n", i, lstpj->name[0]);
						i++;
					}
		}

		if (lstpj->name[0] == 20)
		{
			arr[0] = -1;
			return (1);
		}

		//unplace_piece(arr[i - 1], lstpj, board, boardsize);
		if(lstpj->name[0] == lstp[0].name[0])
			return (0);

		return (0);

/*
		while (i < (boardsize * boardsize))
		{
				printf("i is %d and arr[%d] is %d\n", i, i, arr[i]);
				i++;
		}
		i = 0;
		j = 0;
		while (j < boardsize * boardsize)
		{
				if (j % boardsize == 0)
						printf("\n");
				while (arr[i] != j)
						i++;
				printf("%d\t ", i);
				j++;
				i = 0;
		}
		printf("\n");
		free(arr);
		i = 0;
		while (lstp[i].name[0] != 20)
		{
				printf("lstp[%d].name address %p\n", i, lstp[i].name);
				printf("lstp[%d].name[0] address %p\n", i, &lstp[i].name[0]);
				printf("lstp[%d].name[0] is %d\n", i, lstp[i].name[0]);
				i++;
		}
	*/
}
