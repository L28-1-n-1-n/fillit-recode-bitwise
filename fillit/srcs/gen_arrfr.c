#include "../includes/fillit.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	gen_arr(int *arr)
{
	int		i;
	int		j;

	i = 0; /*Initialize every element of arr, to avoid unpredicted behaviour*/
	while (i < 256)
	{
		arr[i] = 0;
		i++;
	}
	i = 0;
	while (i < 16)
	{
		arr[i * i] = i;
		i++;
	}
	i = 1;

while (i <= 256)
{
	if (arr[i * i] == i)
		{
			j = 0;
			while (j <= i)
			{
				arr[i * i + i + j] = 16 * i + j;
				if (j < i)
					arr[i * i + j] = 16 * j + i;
				j++;
			}
		}
		i++;
	}
}

/*
	while (i <= 256)
	{
		if (arr[i * i] == i)
			{
				j = 1;
				arr[i * i+ 1] = 16 * i;
				while (j < i)
				{
					arr[i * i + 2 * j] = 16 * j + i;
					arr[i * i + 2 * j + 1] = 16 * i + j;
					j++;
				}
				arr[i * i + 2 * j] = 16 * j + i;
			};
		i++;
	}
//	return (arr);
}
*/
/*
int		main()
{
	int *arr;
	int width;
	int i;
	int j;

	width = 16;
	if (!(arr = (int *)malloc(sizeof(int) * width * width)))
		return (0);
	i = 0;
//	arr = gen_arr(width);
	gen_arr(arr);
	while (i < (width * width))
	{
		printf("i is %d and arr[%d] is %d\n", i, i, arr[i]);
		i++;
	}

	i = 0;
	j = 0;
	while (j < width * width)
	{
		if (j % width == 0)
			printf("\n");
		while (arr[i] != j)
			i++;
		printf("%d-%d\t", i, arr[i]);
		j++;
		i = 0;
	}
	printf("\n");

	i = 0;
	j = 0;
	while (j < width * width)
	{
		if (j % width == 0)
			printf("\n");
		while (arr[i] != j)
			i++;
		printf("%d\t", arr[i]);
		j++;
		i = 0;
	}
	printf("\n");

	free(arr);

	return (0);
}
*/
