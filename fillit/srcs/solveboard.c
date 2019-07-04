#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int solveboard(t_p *lstpj, __uint128_t *board, int boardsize, t_p *lstp)
{
		int i;

		i = 0;
		if (lstpj->name[0] == 20)
		{
			lstp[0].found = 1;
			return (1);
		}
		if (lstp[0].found == 1)
			return (1);
//		printf("before placepiece, height is %d\n", lstpj->height);
		while ((!(lstp[0].found)) && (lstpj->name[0] != 20) && (i < boardsize * boardsize))
		{
	//				printf("solveboard before placepiece, height : %d\n", lstpj->height);
					if(place_piece(i, lstpj, board, boardsize))
					{
	//			 		print_board(lstp, boardsize);
						lstpj += 1;
						if (solveboard(lstpj, board, boardsize, lstp))
							return (1);
						else
						{
							lstpj = lstpj - 1;
							unplace_piece(i, lstpj, board, boardsize);
							i++;
						}
/*	unplace piece; using XOR gate: a ^ b (a XOR b) -> all 1 and 1 become zero, so used ^ this piece = undo this piece */
					}
					else
						i++;
		}

		if (lstpj->name[0] == 20)
		{
			lstp[0].found = 1;
			return (1);
		}

		if(lstpj->name[0] == lstp[0].name[0])
			return (0);

		return (0);
}
