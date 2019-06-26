#include "fillit.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> /*to remove*/

/*
void regen_value(t_p *lstp, int w)
{
	int i;

	i = 0;
	while (lstp[i].name[0] != 20)
	{
		while (lstp[i].name[j] != 0)
		{
			lstpj->value = lstpj->value + (lstp[i].name[j] << ( w * w - w * i + w - 4))
			j++;
		}
		i++;
	}
}
*/

int		main(int argc, char **argv)
{
		int		j;
		int		i; /*for debug only, will delete later */
		int		k; /*for debug only, will delete later */
		int		boardsize;
		t_p		*lstp;
		__uint128_t		*board;
		int		*arr;

		double total_time; /*to remove*/
		clock_t start, end; /*to remove*/
		start = clock(); /*to remove*/
		j = 0;
		i = 0;
		k = 0;
		if ((!(board = (__uint128_t *)malloc(sizeof(__uint128_t) * 2))) ||
		(!(arr = (int *)malloc(sizeof(int) * 256))))
			return (0);
		if(!(lstp = (t_p *)malloc(sizeof(t_p) * 27)))
			return (0);
		/*28 becoz 26 + signal end*/
		if (argc != 2)
				return (0);
		if (open(argv[1], O_RDONLY) < 1)
				return (0);
		j = read_blocks((open(argv[1], O_RDONLY)), lstp);
		if (j == ERROR)
	   {
	      write(1, "Error\n", 6);
	      return (0);
	   }
		printf("j is now %d in main\n", j);
		boardsize = ft_lsqrt(j * 4);

		printf("boardsize is %d\n", boardsize);

		while (lstp[i].name[0] != 20)
		{
			k = 0;
			printf("i is %d\t", i);
			while (k < j)
			{
				printf("%d\t", lstp[i].name[k]);
				k++;
			}
			printf("\n");
			i++;
		}
		printf("now we print the names of all pieces in final list\n");
		i = 0;
		while (i < j)
		{
			printf("lstp[%d].name[0] is %d\n", i, lstp[i].name[0]);
			i++;
		}


	//	solveboard(&lstp[0], board, arr, boardsize);

/*		while (!(solveboard(&lstp[0], board, arr, boardsize)))
		{
			gen_board(board);
			solveboard(&lstp[0], board, arr, boardsize+1);
		}
*/

		gen_board(board, boardsize);
		gen_arr(arr);
		while (!solveboard(&lstp[0], board, arr, boardsize, lstp))
		{
			boardsize = boardsize + 1;
			gen_board(board, boardsize);
		//	regen_value(lstp, boardsize);
			printf("A  N E W  B O A R D S I Z E  I S  N O W  A D D E D %d\n", boardsize);
			solveboard(&lstp[0], board, arr, boardsize, lstp);
		}
/*		i = 0;
		while (i < j)
		{
			printf("lstp[%d].value is %d\n", i, lstp[i].value);
			i++;
		}*/
		print_board(lstp, boardsize);
		end = clock(); /*to remove*/
		total_time = ((double) (end - start)/CLOCKS_PER_SEC);
		printf("\nTime taken: %f seconds\n", total_time);
		return (0);
}
