/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:50:51 by hlo               #+#    #+#             */
/*   Updated: 2019/05/03 17:53:26 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lsqrt(int nb)
{
	int s_root;

	s_root = 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (s_root <= nb / s_root)
	{
		if (s_root * s_root == nb)
			return (s_root);
		s_root++;
	}
	return (s_root);
}
