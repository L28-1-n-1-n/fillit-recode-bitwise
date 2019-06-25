#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int		find_offset(int b)
{

	if (b / 8 > 0)
		return (4);
	if (b / 4 > 0)
		return (3);
	if (b / 2 > 0)
		return (2);
	else
		return (1);
}

/*special case is hard coded for simplicity*/
void	special_case(t_p* lstpj, char *final, char alpha, int w)
{
	int a;

	a = (lstpj->pos / w) * 16 + lstpj->pos % w;
	printf("Alpha is %c and a is %d\n",alpha, a);
//	printf("first, a : %d\n", a);
	final[a] = alpha;
	final[a + 16] = alpha;
	final[a + 15] = alpha;
//	printf("we have put %c into final[%d], final[%d] and final[%d]", alpha, a, a+16, a+15);
	if (lstpj->name[0] == 2) /*case ZU*/
	{
//		printf("we have ZU end put %c into final[%d]", alpha, a + 31);
		final[a + 31] = alpha;
	}
	if (lstpj->name[0] == 3) /*case ZR*/
	{
	//	printf("we have ZR end put %c into final[%d]", alpha, a + 1);
		final[a + 1] = alpha;
	}
	if (lstpj->name[0] == 11) /*case TU*/
	{
//		printf("we have TU end put %c into final[%d]", alpha, a + 17);
		final[a + 17] = alpha;
	}
}

void	write_alpha(t_p* lstpj, char *final, char alpha, int w)
{
	int a;
	int b;
	int offset;
	int f_offset;
	int sum;

//	printf("alpha is %c\n", alpha);
	b = 4; /*start from fifth letter of tetri*/
	offset = 0;
	f_offset = find_offset(lstpj->name[b]);
	a = (lstpj->pos / w) * 16 + lstpj->pos % w;
	printf("Alpha is %c and a is %d\n",alpha, a);
//	printf("first value is put into a : %d\n", a);
//	printf("this piece is %d\n", lstpj->name[0]);
//	printf("first offset is %d\n", f_offset);

	while (lstpj->name[b] != -4)
	{
		sum = lstpj->name[b];
		if (find_offset(lstpj->name[b]) < f_offset)
		{
			a = a + f_offset - find_offset(lstpj->name[b]);
			offset = find_offset(lstpj->name[b]);
//			printf("now a is changed to %d\n", a);
		}
		else
		{
			offset = find_offset(lstpj->name[b]);
//			printf("now offset is changed to %d\n",offset);
		}
//		printf("sum to put in: %d\n", sum);
//		printf("offset is now %d\n", offset);
		while (offset)
		{
			if ((sum % 2 == 1) || (sum == 1))
			{
				if (lstpj->name[3] == 1) /*if 4th lettter of tetri is not F*/
				{
					final[a - (offset - 1)] = alpha;
//					printf("a: %d, offset: %d, a-(offset-1): %d\n", a, offset, a-(offset-1));
//					printf("we have put %c into final[%d]\n", alpha, a - (offset-1));
				}
				else
				{
					final[a + (offset - 1)] = alpha;
//					printf("a: %d, offset: %d, a+(offset-1): %d\n", a, offset, a+(offset-1));
//					printf("we have put %c into final[%d]\n", alpha, a + (offset-1));
				}
			}
			sum  = sum / 2;
			offset--;
//			printf("the new sum is %d\n", sum);
//			printf("offset before next loop is %d\n", offset);

		}
		if (find_offset(lstpj->name[b]) < f_offset) /*need to reset a if a was changed*/
			a = a - f_offset + find_offset(lstpj->name[b]) + 16;
		else
			a = a + 16;
//	printf("the new a is %d\n", a);
		b++;
//		printf("now b is %d and lstpj->name[b] is %d\n", b, lstpj->name[b]);
	}
}
/*print_board offset will not work for second line that starts with 0
So need variable to store what is offset for first line. If offset for first line is greater than that of second line, then second line’s offset need to be kept the same, or whatever is the biggest offset in 3 lines.*/

void	print_board(t_p* lstp, int w)
{
	char *final;
	char alpha;
	int i;

	printf("boardsize is %d\n", w);
	i = 0;
	final = (char *)malloc(sizeof(char) * 257);
	while (i < 256)
		final[i++] = '.';
	final[i] = 0;
	i = 0;
	alpha = 'A';
	while ((lstp[i].name[0] != 20) && lstp[i].pos != 400)
	{
		/*how to store the value to be divided without declaring a new variable? */
	/*need to do this loop in another function since this is clearly above 25 lines*/
		if((lstp[i].name[0] == 2) || (lstp[i].name[0] == 3) || (lstp[i].name[0] == 11))
			special_case(&lstp[i], final, alpha, w);
		else
			write_alpha(&lstp[i], final, alpha, w);
		alpha++;
		i++;
	}
	i = 0;
	while (i < 256)
	{
		if (i % 16 == 0)
			printf("\n");
		printf("%c ", final[i]);
		i++;
	}
	free(final);


}
/*scrap the above. declare final as a char * of char of size boardsize * boardsize + 1
then for first line of tetri, # at arri (e.g. 27)and then devide by 2 until you finish #ing the first line
for second line, beginning index is arri + boardsize (e.g. 27 + 8 = 35, then repeat the algo
of dividing by 2 until you finish this line
repeat until you hit -4
board needs to be pre-defined as board[200]
problem to think about is whether each would support 2^200 per integer
the idea is to get rid of as much mallocs as possible
and use strcpy to input data into each integer of the board*/
