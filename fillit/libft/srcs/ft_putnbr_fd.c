/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:57:02 by hlo               #+#    #+#             */
/*   Updated: 2019/01/19 23:05:57 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long nbr_long;

	nbr_long = n;
	if (nbr_long < 0)
	{
		ft_putchar_fd('-', fd);
		nbr_long = -nbr_long;
	}
	if (nbr_long >= 10)
		ft_putnbr_fd(nbr_long / 10, fd);
	ft_putchar_fd('0' + nbr_long % 10, fd);
}
