/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 22:48:52 by hlo               #+#    #+#             */
/*   Updated: 2019/01/30 23:47:46 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int  open_file(const int fd, char *buff)
{
	if (fd < 0 || read(fd, buff, 0) < 0)
		return (ERROR);
	return (read(fd, buff, BUFF_SIZE));
}

int		count_endl(const int fd)
{
	char buff[22];
	int nb;
	int i;
	int n_count;

	i = 0;
	n_count = 0;
	nb = 21;
	while (nb == 21)
	{
		ft_bzero(buff, 22);
		nb = open_file(fd, buff);
		if((nb == 0) || (buff[0] == '\0'))
			return (n_count);
		while (i < 21)
		{
			if (buff[i] == '\n')
				n_count++;
			i++;
		}
		i = 0;
		if (nb != 21)
			return(n_count);
	}
	return (ERROR);
}

int	valid_block(char *temp, t_p *lstpj, int n_count) /*valid_block returns 1 if valid, 0 if not valid*/
{
	int i;
	int count;
	int arr[5];

	count = 0;
	i = -1;
	ft_memset(&arr, -1, sizeof(int) * 5);
	while (i++ < 20)
	{
		if (count == 5)
			return (ERROR);
		if ((((i + 1) % 5 == 0) || i == 20) && (temp[i] != '\n'))
			if ((n_count != 2) || (i != 20))
				return (ERROR);
		if (((i != 20) && ((i + 1) % 5 != 0)) && ((temp[i] != '.') && (temp[i] != '#')))
				return (ERROR);
		if (temp[i] == '#')
		{
			arr[count] = i;
			count++;
		}
	}
	if (count != 4 || arr[0] == -1 || arr[4] != -1)
		return (ERROR);
	return(tetri_offset(arr, lstpj));
}

int		get_next_block(const int fd, t_p *lstpj, int n_count)
{
	char buff[22];
	int nb;

	if (fd < 0 || read(fd, buff, 0) < 0)
		return (ERROR);
	nb = read(fd, buff, BUFF_SIZE);
	if((nb == 0) || (buff[0] == '\0'))
		return (0);
	if ((nb != 21) && (n_count != 2))
		return (ERROR);
	buff[21] = '\0';
	return (valid_block(buff, lstpj, n_count));
}

void init_blocks(t_p *lstp, int n_count)
{
	int ret;

	ret = 0;
	while (ret < n_count)
	{
		define_blocks(NA, &lstp[ret]);
		lstp[ret].pos = 400;
		lstp[ret].value = 0;
		lstp[ret].height = 0;
		lstp[ret].found = 0;
		ret++;
	}
}
int		read_blocks(int fd, t_p *lstp, int n_count)
{
	int			ret;
	int			j;

	j = 0;
	ret = 0;
	init_blocks(lstp, n_count);
	while ((ret = get_next_block(fd, &lstp[j], n_count - j)) > 0)
		j++;
	if (ret == ERROR)
    return (ERROR);
	close(fd);
	return (j);
}
