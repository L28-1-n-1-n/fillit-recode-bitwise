#include  "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int  define_blocks(char *o_arr, t_p *lstpj)
{
	int i;

	i = 0;
  printf("we got to define blocks\n");
  if (o_arr == ER) /*ER block assigned for invalid block*/
		return (ERROR);
  while (i < 9)
	{
		lstpj->name[i] = o_arr[i] - 'E';
		printf("name[%d] is %d\n", i, lstpj->name[i]);
		i++;
	}
  return (1);
}

char  *id_tetri_extend(int num)
{
	if (num == 39)
		return (TU);
	if (num == 281)
    return (TL);
  if (num == 57)
    return (TD);
  if (num == 305)
    return (TR);
  if (num == 51)
    return (S);
  if (num == 71)
    return (LU);
  if (num == 401)
    return (LR);
  if (num == 113)
    return (LD);
  if (num == 275)
    return (LL);
  return (ER);
}

char  *id_tetri(int num)
{
	printf("original num is %d\n", num);
	if (num == 0)
		return (ER);
	while (num % 2 == 0)
    num = num >> 1;
  printf("now num is %d\n", num);
  if (num == 99)
    return (ZL);
  if (num == 153)
    return (ZU);
  if (num == 27)
    return (ZR);
  if (num == 561)
    return (ZD);
  if (num == 4369)
    return (D);
  if (num == 29)
    return (RU);
  if (num == 785)
    return (RR);
  if (num == 23)
    return (RD);
  if (num == 547)
    return (RL);
  if (num == 15)
    return (H);
  return (id_tetri_extend(num));
}

int  valid_block(char *temp, t_p *lstpj)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (i < 21)
	{
		if ((((i + 1) % 5 == 0) || i == 20) && (temp[i] != '\n'))
				return (ERROR); /*all these places should be '\n' */
		if ((((i + 1) % 5 != 0) && (i != 20))
      && (temp[i] != '.') && (temp[i] != '#'))
			   return (ERROR); /*all other places should be '.' or '#' only */
		if (temp[i] == '#')
					num += 1;
		if ((temp[i] == '.') || (temp[i] == '#'))
					num = num << 1;
		i++;
	}
	return (define_blocks(id_tetri(num), lstpj));
}

/*returns 0 if invalide block, returns value (num) of the block
if valid, hence return > 1*/

void init_blocks(t_p *lstp)
{
	int ret;

	ret = 0;
	while (ret < 29)
	{
		/*initialize with null values*/
		define_blocks(NA, &lstp[ret]);
		printf("first names are %d\n", lstp[ret].name[0]);
		lstp[ret].value = 0;
		ret++;
	}
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
	if ((nb != 21) && (nb != 0))
	{
		printf("nb or buff\n");
		return (ERROR);
	}
	buff[21] = '\0';
  if (!(*line = ft_strdup(buff)))
	{
		free(line);
		printf("ZERO HAS BEEN RETURNED\n");
		return (0);
	}
  printf("valid_block returns %d\n", valid_block(buff, lstpj));
	return (valid_block(buff, lstpj));
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
    ft_putstr("printing line:\n");
    ft_putstr(line);
		printf("lstp[%d]->name is %d\n", j, lstp[j].name[0]);
		printf("ret is %d\n", ret);
		j++;
		free(line);
	}

	printf("final value of ret is %d\n", ret);
  if (ret == ERROR)
	{
		printf("There is error\n");
    return (ERROR);
	}
	close(fd);
	printf("j (no. of pieces) is now %d\n", j);
	/*no. of pieces is correct becoz j starts at 0, so if j is now 6, there is 0, 1, 2, 3, 4, 5--> this in total is 6 pieces*/

	return (j); /*output the number of blocks written into lstp*/
}


int  main(int argc, char **argv)
{
  int j;
  t_p *lstp;
	int m;

	m = 0;
  j = 0;
  if(!(lstp = (t_p *)malloc(sizeof(t_p) * 28)))
    return (0);
  if (argc != 2)
      return (0);
  if (open(argv[1], O_RDONLY) < 1)
      return (0);
  j = read_blocks((open(argv[1], O_RDONLY)), lstp);
	while (m <= j)
	{
		printf("m is %d and lstp[%d]->name is %d\n", j, m, lstp[m].name[0]);
		m++;
	}
  if (j == ERROR)
    {
      write(1, "Error\n", 6);
      return (0);
    }
  printf("j is %d in main\n",j);
  return (0);
}
