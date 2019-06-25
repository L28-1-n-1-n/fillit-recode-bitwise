#include <stdio.h>

int *arrnum()
{
	int board[10];
	int i;

	i = 0;
	while (i < 10)
	{
		board[i] = -4;
		i++;
	}
	while (i--)
		printf("board[%d] is %d", i, board[i]);
	return (board);
}

int		main()
{
	int *arr;

	arr = arrnum();
	while (*arr)
	{
		printf("%d\n", *arr);
		arr++;
	}
	return (0);
}
