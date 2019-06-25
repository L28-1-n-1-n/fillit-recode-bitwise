#include "fillit.h"
#include "stdio.h"
#include "stdlib.h"

int		issafe(int i, int *name, int w, int *arr)
{
	(void )arr;

	if ((name[0] == 3) || (name[0] == 11))
		{
			if ((i % w + name[2] >= 0) && (i % w + name[1] < w))
				if ((i / w + name[3] < w))
					if (i < w * w)
						return (1);
		}
	else
		{
			if ((i % w + name[1] >= 0) && (i % w + name[1] < w))
				{
					if ((i / w + name[2]) < w)
						if (i < w * w)
							return (1);
				}
		}
		return (0);
}
/*
int		issafe(int i, int *name, int w, int *arr)
{
	if ((name[0] == 3) || (name[0] == 11))
		{
			if ((arr[i] % 16 + name[2] >= 0) && (arr[i] % 16 + name[1] < w))
				if ((arr[i] / 16 + name[3] < w))
					if (i < w * w)
						return (1);
		}
	else
		{
			if ((arr[i] % 16 + name[1] >= 0) && (arr[i] % 16 + name[1] < w))
				{
					if ((arr[i] / 16 + name[2]) < w)
						if (i < w * w)
							return (1);
				}
		}
		return (0);
}
*/
/*
int		main()
{
	int w;
	int i;
	int j;
	int *arr;
	t_p *lstptest;

	w = 16;

	if(!(lstptest = (t_p *)malloc(sizeof(t_p) * 1)))
		return (0);
	if (!(arr = (int *)malloc(sizeof(int) * 256)))
		return (0);
	gen_arr(arr);
	define_blocks(LL, lstptest);

	i = 0;
	j = 0;
	while (j < w * w)
	{
		if (j % w == 0)
			printf("\n");
		while (arr[i] != j)
			i++;
	//	printf("%d-%d-%d\t", i, arr[i], issafe(i, lstptest->name, w, arr));
		printf("%d\t", issafe(i, lstptest->name, w, arr));
		//i is rank and arr[i] is the actual index
		j++;
		i = 0;
	}
	printf("\n");
}
*/
