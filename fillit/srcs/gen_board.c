#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void  gen_upperboard(__uint128_t *board, int w, int i)
{
	while (i <= 8)
	{
		board[0] += ((__uint128_t)1 << (128 - 16 * i + (16 - w - 1)));
		i++;
	}
	while (i <= w)
	{
		board[1] += ((__uint128_t)1 <<
		(128 - 16 * (i - 8) + (16 - w - 1)));
		i++;
	}
	board[1] += ((__uint128_t)65535 << ((16 - w - 1)) * 16);
}
void	gen_board(__uint128_t *board, int w)
{
	int i;

	board[0] = (__uint128_t)0;
	board[1] = (__uint128_t)0;
	i = 1;
	if (w < 8)
	{
		while (i <= w)
		{
			board[0] += ((__uint128_t)1 << (128 - 16 * i + (16 - w - 1)));
			i++;
		}
		board[0] += ((__uint128_t)65535 << ((8 - w -1) * 16));
	}
	else
			gen_upperboard(board, w, i);
}

void	write_alpha(t_p* lstpj, char *final, char alpha, int w)
{
	int i;
	int k;

	i = 3;
	k = 1;
	while(lstpj->name[k] != 0)
	{
		while (i >= 0)
		{
			if ((lstpj->name[k] >> (3 - i)) % 2)
				final[lstpj->pos + i + w * (k - 1)] = alpha;
			i--;
		}
		i = 3;
		k++;
	}
}

void	print_board(t_p* lstp, int w)
{
	char *final;
	char alpha;
	int i;

	i = 0;
	if (!(final = (char *)malloc(sizeof(char) * (w * w))))
		return ;
	while (i < w * w)
		final[i++] = '.';
	final[i] = 0;
	i = 0;
	alpha = 'A';
	while ((lstp[i].name[0] != 20) && lstp[i].pos != 400)
		write_alpha(&lstp[i++], final, alpha++, w);
	i = 0;
	while ((i < w * w + 1) && final[i])
	{
		if (i > 0 && (i % w == 0))
			write(1,"\n", 1);
		write(1, &final[i], 1);
		i++;
	}
	write(1,"\n", 1);
	free(final);
}
