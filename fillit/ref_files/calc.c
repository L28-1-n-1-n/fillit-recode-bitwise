#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//typedef unsigned __int128 uint128_t;

void gen_board(__uint128_t *board)
{
	board[0] = (__uint128_t)1 << 78;
	board[0] = board[0] >> 27;
	board[1] = (__uint128_t)1 << 127;
	board[1] = board[1] >> 63;
}

int	main ()
{
/*	__uint128_t value;
	//unsigned __int128 value;
	value = (__uint128_t)1 << 78;
	value = value >>27;
	printf("value is %llu", (uint64_t)value);
*/	
	__uint128_t *board;
	if (!(board = (__uint128_t *)malloc(sizeof(__uint128_t) * 2)))
		return (0);
	gen_board(board);
	printf("value of board[0] is %llu", (uint64_t)board[0]);
	printf("value of board[1] is %llu", (uint64_t)board[1]);
	uint64_t exp;
	exp = (uint64_t) 224 << 56;
	printf("value of exp is %llu\n", (uint64_t)exp);
	printf("sizeof __uint128_t is %lu\n", sizeof(__uint128_t *));
	return (0);
}
