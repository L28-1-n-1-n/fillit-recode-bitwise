#include "fillit.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> /*to remove*/
int   print_usage()
{
	//write(1, "usage: ./fillit <file name>\n", 28);
	return (0);
}

int		main(int argc, char **argv)
{
		int		j;
		int n_count;
		int fd;
		int		boardsize;
		t_p		*lstp;
		__uint128_t		*board;

		double total_time; /*to remove*/
		clock_t start, end; /*to remove*/
		start = clock(); /*to remove*/

		j = 0;
		n_count = 0;
		if (argc != 2)
				return (print_usage());
		fd = open(argv[1], O_RDONLY);
		if ((fd) < 1)
				return (print_usage());
		n_count = count_endl(fd);
		printf("n_count in main is %d\n", n_count);
		if ((n_count <= 0) || (n_count % 5 != 4))
		{
			close(fd);
			return(print_usage());
		}
		n_count = n_count / 5 + 1;
		printf("no. of blocks is %d\n", n_count);
		if ((!(board = (__uint128_t *)malloc(sizeof(__uint128_t) * 2)) ||
				(!(lstp = (t_p *)malloc(sizeof(t_p) * (n_count + 1))))))
			return (0);
		/*27 becoz 26 + 1 block to signal end of block stream*/
		if (open(argv[1], O_RDONLY) < 1)
				return (print_usage());
		j = read_blocks((open(argv[1], O_RDONLY)), lstp, n_count + 1);

		if (j == ERROR)
			return (print_usage());
		boardsize = ft_lsqrt(j * 4); /*gives minimum possible width to begin with*/
		gen_board(board, boardsize);

		/*debugging*/
/*
		int		k;
		k = 0;
		while (k < 27)
		{
			printf("lstpj->height is %d\n", lstp[k].height);
			k++;
		}*/
		/*end of debug*/

		while (!solveboard(&lstp[0], board, boardsize, lstp))
		{
			boardsize = boardsize + 1;
			gen_board(board, boardsize);

	//		printf("A  N E W  B O A R D S I Z E  I S  N O W  A D D E D %d\n", boardsize);
			solveboard(&lstp[0], board, boardsize, lstp);
		}

		print_board(lstp, boardsize);

		end = clock(); /*to remove*/
		total_time = ((double) (end - start)/CLOCKS_PER_SEC); /*to remove*/
	//	printf("Time taken: %f seconds\n", total_time); /*to remove*/

		return (0);
}
