/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreffers <sreffers@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:09:36 by sreffers          #+#    #+#             */
/*   Updated: 2025/09/30 17:22:04 by sreffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_fd(int n, int fd, int *count)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd, count);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd, count);
	}
	ft_putchar_fd(nbr % 10 + '0', fd, count);
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *count)
{
	if (n > 9)
	{
		ft_putnbr_unsigned_fd(n / 10, fd, count);
	}
	ft_putchar_fd(n % 10 + '0', fd, count);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr_base(unsigned int nbr, char *base, int *count)
{
	int		size;
	long	n;

	n = nbr;
	size = ft_strlen(base);
	if (n >= size)
		ft_putnbr_base(n / size, base, count);
	ft_putchar_fd(base[n % size], 1, count);
}

void	ft_putnbr_base_long(unsigned long nbr, char *base, int *count)
{
	int		size;
	long	n;

	n = nbr;
	size = ft_strlen(base);
	if (n >= size)
		ft_putnbr_base(n / size, base, count);
	ft_putchar_fd(base[n % size], 1, count);
}
