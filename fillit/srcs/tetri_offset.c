#include "fillit.h"

//tetri_offset is called after only 4# is found in each block
//it loops through tetri_offset, which calls id_tetri, which calls id_tetri_extend to idenfift the tetrimino
//if the 4#'s positions do not match any tetrimino, return NULL
//The NULL returned should be interpreted as error in read_block

/*

Also: how to check if all pieces are neighbouring each other:
For each piece, all neighbouring position are unique offsets that together form a circle around the piece. Just need to check if the side is not by the border, then these neibouring positions / offsets must NOT be all dots (if all dots, then isolated piece.

*/





char *id_tetri_extend(int *arr)
{
	if ((arr[1] == 1) && (arr[2] == 2))
	{
		if (arr[3] == 3)
			return (H);
		if (arr[3] == 5)
			return (RU);
		if (arr[3] == 6)
			return (TD);
		if (arr[3] == 7)
			return (LD);
	}
	if (arr[1] == 5)
	{
		if ((arr[2] == 6) && (arr[3] == 7))
			return (LU);
		if ((arr[2] == 6) && (arr[3] == 10))
			return (TL);
		if ((arr[2] == 6) && (arr[3] == 11))
			return (ZD);
		if ((arr[2] == 9) && (arr[3] == 10))
			return (LL);
		if ((arr[2] == 10) && (arr[3] == 11))
			return (RL);
		if ((arr[2] == 10) && (arr[3] == 15))
			return (D);
	}
	return (ER);
}

char *id_tetri(int *arr)
{
	if ((arr[1] == 1) && (arr[2] == 4) && (arr[3] == 5))
		return (ZR);
	if ((arr[1] == 1) && (arr[2] == 6) && (arr[3] == 7))
		return (ZL);
	if ((arr[1] == 1) && (arr[2] == 6) && (arr[3] == 11))
		return (RR);
	if ((arr[1] == 1) && (arr[2] == 5) && (arr[3] == 6))
		return (S);
	if ((arr[1] == 1) && (arr[2] == 5) && (arr[3] == 10))
		return (LR);
	if ((arr[1] == 3) && (arr[2] == 4) && (arr[3] == 5))
		return (RD);
	if ((arr[1] == 4) && (arr[2] == 5))
	{
		if (arr[3] == 6)
			return (TU);
		if (arr[3] == 10)
			return (TR);
		if (arr[3] == 9)
			return (ZU);
	}
	return (id_tetri_extend(arr));
}

int  tetri_offset(int *arr, t_p *lstpj)
{
	int	tmp;
	int i;

	i = 0;
	tmp = arr[0];
	while (i < 4)
	{
		arr[i] = arr[i] - tmp;
		i++;
	}
	return (define_blocks(id_tetri(arr), lstpj));
}
