/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreffers <sreffers@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:44:56 by sreffers          #+#    #+#             */
/*   Updated: 2025/09/30 17:34:50 by sreffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	write_args(const char *str, va_list args, int *count)
{
	if (str[1] == 'c')
		ft_putchar_fd(va_arg(args, int), 1, count);
	else if (str[1] == '%')
		ft_putchar_fd('%', 1, count);
	else if (str[1] == 's')
		ft_putstr_fd(va_arg(args, char *), 1, count);
	else if (str[1] == 's')
		ft_putstr_fd(va_arg(args, char *), 1, count);
	else if (str[1] == 'i' || str[1] == 'd')
		ft_putnbr_fd(va_arg(args, int), 1, count);
	else if (str[1] == 'u')
		ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1, count);
	else if (str[1] == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", count);
	else if (str[1] == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	else if (str[1] == 'p')
	{
		ft_putstr_fd("0x", 1, count);
		ft_putnbr_base_long((unsigned long)va_arg(args, void *),
			"0123456789abcdef", count);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int	count;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && is_specifier(str[i + 1]))
		{
			write_args(str + i, args, &count);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1, &count);
		}
		i++;
	}
	va_end(args);
	return count;
}

/*#include <stdio.h>

int	main(void)
{
	int a = printf("bjr %d %x %s\n", 115, -2147483647 ,"hello");
	int b = ft_printf("bjr %d %x %s\n", 115, -2147483647 , "hello");

	printf("%d\n%d\n", a, b);
}*/
