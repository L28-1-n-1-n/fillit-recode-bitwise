#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int 	print_file_error()
{
	write(1, "failed to open file\n", 20);
	return (0);
}

int   print_error()
{
	write(1, "error\n", 6);
	return (0);
}

int   print_usage()
{
	write(1, "usage: ./fillit <file name>\n", 28);
	return (0);
}

int   output_solution(int fd, t_p *lstp, int n_count, __uint128_t *board)
{
	int		j;
	int		boardsize;

	if (fd < 1)
			return (print_usage());
	j = read_blocks(fd, lstp, n_count + 1);
	if (j == ERROR)
		return (print_error());
	boardsize = ft_lsqrt(j * 4);
	gen_board(board, boardsize);
	while (!solveboard(&lstp[0], board, boardsize, lstp))
	{
		boardsize += 1;
		gen_board(board, boardsize);
		solveboard(&lstp[0], board, boardsize, lstp);
	}
	print_board(lstp, boardsize);
	free(board);
	free(lstp);
	return (0);
}

int		main(int argc, char **argv)
{
		int n_count;
		int fd;
		t_p		*lstp;
		__uint128_t		*board;

		if (argc != 2)
				return (print_usage());
		fd = open(argv[1], O_RDONLY);
		if ((fd) < 1)
				return (print_file_error());
		n_count = count_endl(fd);
		if ((n_count <= 0) || (n_count % 5 != 4) || (n_count > 129))
		{
			close(fd);
			return(print_error());
		}
		n_count = n_count / 5 + 1;
		if ((!(board = (__uint128_t *)malloc(sizeof(__uint128_t) * 2)) ||
				(!(lstp = (t_p *)malloc(sizeof(t_p) * (n_count + 1))))))
			return (0);
		fd = open(argv[1], O_RDONLY);
		return (output_solution(fd, lstp, n_count, board));
}
