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
	char buff[22]; /*needs to be 1 more than 21 so error blocks longer than 21 units can be read*/
	int nb;
	int i;
	int n_count;

	i = 0;
	n_count = 0;
	nb = 21;

	while ((nb == 21) && (i < 130))
	{
		ft_bzero(buff, 22);
		nb = open_file(fd, buff);
	/*End-Of-File condition is when no more bytes are read*/
		if((nb == 0) || (buff[0] == '\0')) /*/dev/zero file*/
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
	return (ERROR); //becoz you would have read 26 pieces, and the last char is \n in buff[20], so error
}



int	valid_block(char *temp, t_p *lstpj)
{
	/*valid_block returns 1 if valid, 0 if not valid*/
	int i;
	int count;
	int arr[5];

	i = 0;
	count = 0;
	i = 0;
	while (i < 5)
		arr[i++] = -1;
	i = 0;
	while ((i < 21))
	{
		if (count == 5)
			return (ERROR);
		if ((((i + 1) % 5 == 0) || i == 20) && (temp[i] != '\n'))
			return (ERROR); /*Check if all postions that are supposed to be \n is actually \n*/
		if (((i != 20) && ((i + 1) % 5 != 0)) && ((temp[i] != '.') && (temp[i] != '#')))
			return (ERROR); /*Check if all other positions are occupied by either '.' or '#' only*/
		if (temp[i] == '#')
		{
			arr[count] = i;
			count++;
		}
		i++;
	}/*input the positions or index of all '#' into an array of size 5, so that arr[0] - arr[3] will be positive, and since only 4 '#' should be preseent, content of arr[4] should remain '-1'*/
	i = 0;

	if (count != 4 || arr[0] == -1 || arr[4] != -1)
		return (ERROR);
	/*count != 4 --> less than 4 '#' found; arr[4] != -1 --> more than 4 '#' found */

	return(tetri_offset(arr, lstpj));
}

int		get_next_block(const int fd, t_p *lstpj)
{
	char buff[22]; /*needs to be 1 more than 21 so error blocks longer than 21 units can be read*/
	int nb;

	if (fd < 0 || read(fd, buff, 0) < 0)
		return (ERROR);
	nb = read(fd, buff, BUFF_SIZE);
	/*End-Of-File condition is when no more bytes are read*/
	if((nb == 0) || (buff[0] == '\0')) /*/dev/zero file*/
		return (0);
	if (nb != 21)
	{
		//ft_putstr("nb read is not 21\n");/*the block read is less than 21 */
			return (ERROR);
	}
	buff[21] = '\0'; /*change the last "\n" into \0*/
	return (valid_block(buff, lstpj));
}

void init_blocks(t_p *lstp)
{
	int ret;

	ret = 0;
	while (ret < 28)
	{
		/*initialize with null values*/
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

	init_blocks(lstp);
	while ((ret = get_next_block(fd, &lstp[j])) > 0)
		j++;
	if (ret == ERROR)
    return (ERROR);
	close(fd);
	/*no. of pieces is correct becoz j starts at 0, so if j is now 6, there is 0, 1, 2, 3, 4, 5--> this in total is 6 pieces after j++ */
	return (j); /*output the number of blocks written into lstp*/
}
