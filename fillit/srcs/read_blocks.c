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

int	valid_block(char *temp, t_p *lstpj)
{
	/*valid_blocl returns 1 if valid, 0 if not valid*/
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
	}/*input the positions or index of all '#' into an array of taile 5, so that arr[0] - arr[3] will be positive, and since only 4 '#' should be preseent, content of arr[4] should remain '-1'*/
	i = 0;
	//This loop prints arr which holds current pos of all '#'
/*
	while ((arr[i]) && (i < 4))
	{
		printf("i is %d and arr[i] is %d\n", i, arr[i]);
		i++;
	}
*/
	if (count != 4 || arr[0] == -1 || arr[4] != -1)
	{
		printf("error block");
		return (ERROR);
	}
	/*count != 4 --> less than 4 '#' found; arr[4] != -1 --> more than 4 '#' found */
	tetri_offset(arr, lstpj);
//	printf("This tetrimino is %d\n", lstpj->name[0]);
	return(tetri_offset(arr, lstpj));
}

int		get_next_block(const int fd, char **line, t_p *lstpj)
{
	char buff[22];
	int nb;

	if (!line || fd < 0 || read(fd, buff, 0) < 0)
	{
		printf("no line\n");
		return (ERROR);
	}
	nb = read(fd, buff, BUFF_SIZE);
	/*End-Of-File condition is when no more bytes are read*/
	if((nb == 0) || (buff[0] == '\0')) /*/dev/zero file*/
	{
		printf("ZERO RETURNED BECOZ OF NB\n");
		return (0);
	}
	if (nb != 21)
	{
		ft_putstr("nb read is not 21\n");/*the block read is less than 21 */
		return (ERROR);
	}
	buff[21] = '\0';
	if (!(*line = ft_strdup(buff)))
	{
		free(line);
		return (0);
	}
//	printf("valid_block returns %d\n", valid_block(buff, lstpj));
	return (valid_block(buff, lstpj));
}

void init_blocks(t_p *lstp)
{
	int ret;

	ret = 0;
	while (ret < 29)
	{
		/*initialize with null values*/
		define_blocks(NA, &lstp[ret]);
//		printf("first names are %d\n", lstp[ret].name[0]);
		lstp[ret].pos = 400;
		lstp[ret].value = 0;
		ret++;
	}
}
int		read_blocks(int fd, t_p *lstp)
{
	int			ret;
	char		*line;
	int			j;

	j = 0;
	ret = 0;

	init_blocks(lstp);
	while ((ret = get_next_block(fd, &line, &lstp[j])) > 0)
	{
		ft_putstr(line); /*the whlole ordeal with line shall be deleted*/
//		printf("lstp[j]->name is %d\n", lstp[j].name[0]);
		j++;
		free(line);
	}
	if (ret == ERROR)
	{
		printf("There is error\n");
    return (ERROR);
	}
	close(fd);
//	printf("j (no. of pieces) is now %d\n", j);
	/*no. of pieces is correct becoz j starts at 0, so if j is now 6, there is 0, 1, 2, 3, 4, 5--> this in total is 6 pieces*/
	return (j); /*output the number of blocks written into lstp*/
}

/*

int issafe(int arri, int *name (= lstpj.name), int width)
	if width or  height dont fit
		return (0);
	return (1);

int main
{
	boardsize = formula;
	while (solveboard == false)
	{
		reset all board elements to 0;
		solveboard(lstp, boardsize + 1);
	}
	print board;
}

int solveboard(lstp, boardsize)
{
	int *arr;
	arr = get_arr(boardsize);
	if end of lstp list
		return true;
	while (! end of lstp list && !end of arr)
	{
		if (issafe(arr, lstpj))
		{
			place piece by & ;

			if no overlap
				solveboard(lstp + 1, boardsize);
		}
		else (either over boundary, so not safe, or current pos overlap)
			arr++;
	}

	if end of lstp list
		return true;

	return false;
}

int solveboard(lstp, boardsize)
{
	i = 0; (start arr at pos 0 for each call to solveboard)

	if end of lstp list
		return true;

	while (! end of lstp list && !end of arr)
	{
		if (placepiece(arri, boardsize))
			if (solveboard(lstp+1, boardsize))
				return (1);
			else //if solveboard fails
				unplace_piece;
		else
			i++; (increment arri)
	}

	if end of lstp list
		return true;

	return false;
}













*/
