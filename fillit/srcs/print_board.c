#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* This prints width x width only */

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
			if ((lstpj->name[k] >> (3 - i)) % 2) // so we get >>0 , >> 1, >> 2 , >>3)
				final[lstpj->pos + i + w * (k - 1)] = alpha; // so we get +3, +2, + 1, +0, and first k-1 = 0
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

	//printf("boardsize is %d\n", w);
	i = 0;
	final = (char *)malloc(sizeof(char) * (w * w));
	while (i < w * w)
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
	while (i < w * w + 1)
	{
		if (i > 0 && (i % w == 0))
			write(1,"\n", 1);
		write(1, &final[i], 1);
		i++;
	}
	free(final);
}


/*the following prints 16 x 16 with space, easier to see for debug*/

/*
void	write_alpha(t_p* lstpj, char *final, char alpha, int w)
{
	int i;
	int k;
	unsigned int new_pos;

	i = 3;
	k = 1;
	new_pos = (lstpj->pos / w) * 16 + lstpj->pos % w;	//translate position from i based dependent on w, to 16 based

	while(lstpj->name[k] != 0)
	{
		while (i >= 0)
		{
			if ((lstpj->name[k] >> (3 - i)) % 2) // so we get >>0 , >> 1, >> 2 , >>3)
				final[new_pos + i + 16 * (k - 1)] = alpha; // so we get +3, +2, + 1, +0, and first k-1 = 0
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
			write(1,"\n", 1);
		write(1, &final[i], 1);
		write(1, " ", 1);
		i++;
	}
	free(final);
}
*/
