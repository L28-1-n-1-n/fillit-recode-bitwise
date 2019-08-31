#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
