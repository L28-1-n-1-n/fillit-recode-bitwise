/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:59:19 by hlo               #+#    #+#             */
/*   Updated: 2019/08/31 13:06:02 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place_upperboard(int i, t_p *lstpj, __uint128_t *board, int w)
{
	if ((i / w) + lstpj->height <= 8)
	{
		if (board[0] &
				((__uint128_t)(lstpj->value >>
					((i / w) * 16 + i % w))))
			return (0);
		board[0] |=
			((__uint128_t)(lstpj->value >> ((i / w) * 16 + i % w)));
	}
	else
	{
		if (board[0] & ((__uint128_t)
					(lstpj->value >> ((i / w) * 16 + i % w))))
			return (0);
		if (board[1] &
				((__uint128_t)((lstpj->value <<
						(i / w + lstpj->height - 8) * 16) >> i % w)))
			return (0);
		board[0] |= ((__uint128_t)
				(lstpj->value >> ((i / w) * 16 + i % w)));
		board[1] |= ((__uint128_t)((lstpj->value <<
						(i / w + lstpj->height - 1 - 8) * 16) >> i % w));
	}
	return (1);
}

int		place_piece(int i, t_p *lstpj, __uint128_t *board, int w)
{
	if ((i / w) > 7)
	{
		if (board[1] &
				((__uint128_t)(lstpj->value >> ((i / w - 8) * 16 + i % w))))
			return (0);
		board[1] |=
			((__uint128_t)(lstpj->value >> ((i / w - 8) * 16 + i % w)));
	}
	else if (!(place_upperboard(i, lstpj, board, w)))
		return (0);
	lstpj->pos = i;
	return (1);
}

void	unplace_piece(int i, t_p *lstpj, __uint128_t *board, int w)
{
	if ((i / w) > 7)
	{
		board[1] = (board[1] ^ ((__uint128_t)
					(lstpj->value >> ((i / w - 8) * 16 + i % w))));
	}
	else
	{
		if ((i / w) + lstpj->height <= 8)
		{
			board[0] = (board[0] ^ ((__uint128_t)
						(lstpj->value >> ((i / w) * 16 + i % w))));
		}
		else
		{
			board[0] = (board[0] ^ ((__uint128_t)
						(lstpj->value >> ((i / w) * 16 + i % w))));
			board[1] = (board[1] ^ ((__uint128_t)((lstpj->value <<
								(i / w + lstpj->height - 8) * 16) >> i % w)));
		}
	}
	lstpj->pos = 400;
}

int		ending_conditions(t_p *lstpj, t_p *lstp)
{
	if (lstpj->name[0] == 20)
	{
		lstp[0].found = 1;
		return (1);
	}
	if (lstpj->name[0] == lstp[0].name[0])
		return (0);
	return (0);
}

int		solve(t_p *lstpj, __uint128_t *board, int bsize, t_p *lstp)
{
	int i;

	i = 0;
	if ((lstpj->name[0] == 20) || (lstp[0].found == 1))
	{
		lstp[0].found = 1;
		return (1);
	}
	while ((!(lstp[0].found)) && (lstpj->name[0] != 20) &&
			(i < bsize * bsize))
		if (place_piece(i, lstpj, board, bsize))
		{
			lstpj += 1;
			if (solve(lstpj, board, bsize, lstp))
				return (1);
			else
			{
				lstpj = lstpj - 1;
				unplace_piece(i, lstpj, board, bsize);
				i++;
			}
		}
		else
			i++;
	return (ending_conditions(lstpj, lstp));
}
