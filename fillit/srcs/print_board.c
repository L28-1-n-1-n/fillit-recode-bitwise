#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

void	write_alpha(t_p* lstpj, char *final, char alpha, int w)
{
	unsigned int i;
	unsigned int k;
	unsigned int new_pos;

	i = 3;
	k = 1;
	new_pos = (lstpj->pos / w) * 16 + lstpj->pos % w; /*translate position from i based dependent on w, to 16 based*/
	while(lstpj->name[k] != 0)
	{
		while (i)
		{
			if ((lstpj->name[k] >> (3 - i)) % 2) /* so we get >>0 , >> 1, >> 2 , >>3)*/
				final[new_pos + i + 16 * (k - 1)] = alpha; /* so we get +3, +2, + 1, +0, and first k-1 = 0 */
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

	printf("boardsize is %d\n", w);
	i = 0;
	final = (char *)malloc(sizeof(char) * 256);
	while (i < 256)
		final[i++] = '.';
	final[i] = 0;
	i = 0;
	alpha = 'A';
	while ((lstp[i].name[0] != 20) && lstp[i].pos != 400)
	{
		write_alpha(&lstp[i], final, alpha, w);
		alpha++;
		i++;
	}
	i = 0;
	while (i < 256)
	{
		if (i % 16 == 0)
			printf("\n");
		printf("%c ", final[i]);
		i++;
	}
	free(final);
}
