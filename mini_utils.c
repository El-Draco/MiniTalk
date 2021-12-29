/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:39:04 by rriyas            #+#    #+#             */
/*   Updated: 2021/12/27 20:55:10 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		write(1, "(null)", 6);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_base(long long nbr, char *base)
{
	long	n;
	int		neg;

	neg = 0;
	if (nbr < 0)
		neg = 1;
	n = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n < 10)
		write(1, &base[n], 1);
	if (n >= 10)
	{
		ft_putnbr_base(n / 10, base);
		write(1, &base[n % 10], 1);
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	min;

	min = 1;
	i = 0;
	num = 0;
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (-1);
		num *= 10;
		num += nptr[i] - 48;
		i++;
	}
	return (num * min);
}
