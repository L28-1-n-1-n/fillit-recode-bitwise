#include "fillit.h"
#include <stdio.h>

//int		place_piece(int arri, t_p *lstpj, int *board, int boardsize)
int		place_piece(int i, t_p *lstpj, int *board, int w)
{
	int offset;
	int a;
//	int i;
	int pos;
	int tmp;
	int b;
//	printf("boardsize is %d in place_piece\n", boardsize);
//	if ((arri / 16 > boardsize) || (arri % 16 > boardsize))
//		return (0);
	((lstpj->name[0] == 3) || (lstpj->name[0] == 11)) ? (a = 4) : (a = 3);
	offset = 16 - i % w - lstpj->name[a];

	pos = i;
	tmp = i / w;
	i = a + 1;
	b = a + 1;
	a = tmp;
//	printf("place piece : piece: %d, offset : %d, arri: %d, i is %d and a is %d\n", lstpj->name[0], offset,  arri, i, a);

	/*use & to test whether the spots required have already been taken*/
	/*this is a different test from issafe, which only test for whether the position overflows the border*/
	while (lstpj->name[i] != -4)
	{
		if (board[tmp] & (lstpj->name[i] << offset))
			return (0);
		if (( 1<< (16 - w - 1)) & (lstpj->name[i] << offset))
			return (0);
		if (tmp == w)
		{
	//		printf("rejecting tmp now %d\n", tmp);
			return (0);
		}
		i++;
		tmp++;
	}
	i = b;
	while (lstpj->name[i] != -4)
	{
		board[a] |= (lstpj->name[i] << offset);
//		printf("b is %d, lstpj->name[%d] is %d and board[%d] is %d\n", b, i, lstpj->name[i], a, board[a]);
		a++;
		i++;
	}
	lstpj->pos = pos;
// returns 1 if suceessful, i.e. no overlap
// returns 0 if overlap or boardsize < minimum size of piece
	return (1);
}
