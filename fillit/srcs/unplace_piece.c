#include "fillit.h"
#include <stdio.h>

void	unplace_piece(int i, t_p *lstpj, int *board, int w)
{
	int offset;
	int a;
//	int i;
	int j;

//	printf("Unplace piece: boardsize is %d\n", boardsize);

	j = 0;
//	printf("This piece to unplace is %d and arri is %d\n", lstpj->name[0], arri);

	((lstpj->name[0] == 3) || (lstpj->name[0] == 11)) ? (a = 4) : (a = 3);
	offset = 16 - i % w - lstpj->name[a];
	//printf("offset for unplace piece is %d\n", offset);

	j = a + 1;
	a = i / w;
//	printf("i is %d and a is %d\n", i, a);

	while (lstpj->name[j] != -4)
	{
		board[a] = (board[a] ^ (lstpj->name[j] << offset));
//		printf("lstpj->name[%d] is %d and board[%d] is %d\n", i, lstpj->name[i], a, board[a]);
		a++;
		j++;
	}
	lstpj->pos = 400;
// use XOR operation (a ^ b) to toggle: all 1 and 1 becomes zero, so board[a], which already has this piece in it, board[a] ^ this piece --> this piece is undone
}
