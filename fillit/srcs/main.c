/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:40:17 by hlo               #+#    #+#             */
/*   Updated: 2019/09/17 11:39:45 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		open_file(const int fd, char *buff)
{
	if (fd < 0 || read(fd, buff, 0) < 0)
		return (ERROR);
	return (read(fd, buff, BUFF_SIZE));
}

int		count_endl(const int fd)
{
	char	buff[22];
	int		nb;
	int		i;
	int		n_count;

	i = 0;
	n_count = 0;
	nb = 21;
	while (nb == 21)
	{
		ft_bzero(buff, 22);
		nb = open_file(fd, buff);
		if ((nb == 0) || (buff[0] == '\0'))
			return (n_count);
		while (i < 21)
		{
			if (buff[i] == '\n')
				n_count++;
			i++;
		}
		i = 0;
		if (nb != 21)
			return (n_count);
	}
	return (ERROR);
}

int		print_message(int i)
{
	if (i == USAGE_ERROR)
		write(1, "usage: ./fillit <file name>\n", 28);
	else
	{
		if (i == BLOCK_ERROR)
			write(1, "error\n", 6);
		else
			write(1, "failed to open file\n", 20);
	}
	return (0);
}

int		output_solution(int fd, t_p *lstp, int n_count, __uint128_t *board)
{
	int		j;
	int		bsize;

	if (fd < 1)
		return (print_message(USAGE_ERROR));
	j = read_blocks(fd, lstp, n_count + 1);
	if (j == ERROR)
	{
		free(board);
		free(lstp);
		return (print_message(BLOCK_ERROR));
	}
	bsize = ft_lsqrt(j * 4);
	gen_board(board, bsize);
	while (!solve(&lstp[0], board, bsize, lstp))
	{
		bsize += 1;
		gen_board(board, bsize);
		solve(&lstp[0], board, bsize, lstp);
	}
	print_board(lstp, bsize);
	free(board);
	free(lstp);
	return (0);
}

int		main(int argc, char **argv)
{
	int			n_count;
	int			fd;
	t_p			*lstp;
	__uint128_t	*board;

	if (argc != 2)
		return (print_message(USAGE_ERROR));
	fd = open(argv[1], O_RDONLY);
	if ((fd) < 1)
		return (print_message(OPEN_ERROR));
	n_count = count_endl(fd);
	if ((n_count <= 0) || (n_count % 5 != 4) || (n_count > 129))
	{
		close(fd);
		return (print_message(BLOCK_ERROR));
	}
	n_count = n_count / 5 + 1;
	if ((!(board = (__uint128_t *)malloc(sizeof(__uint128_t) * 2)) ||
				(!(lstp = (t_p *)malloc(sizeof(t_p) * (n_count + 1))))))
		return (0);
	fd = open(argv[1], O_RDONLY);
	return (output_solution(fd, lstp, n_count, board));
}
