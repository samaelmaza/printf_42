/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreffers <sreffers@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:44:56 by sreffers          #+#    #+#             */
/*   Updated: 2025/10/02 00:48:01 by sreffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointers(va_list args, int *count)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1, count);
		return ;
	}
	ft_putstr_fd("0x", 1, count);
	ft_putnbr_base_long((unsigned long)ptr,
		"0123456789abcdef", count);
}

void	write_args(const char *str, va_list args, int *count)
{
	if (str[1] == 'c')
		ft_putchar_fd(va_arg(args, int), 1, count);
	else if (str[1] == '%')
		ft_putchar_fd('%', 1, count);
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
		print_pointers(args, count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

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
	return (count);
}

/*#include <stdio.h>

int	main(void)
{
	int a = printf("bjr %p %p\n", (void*)0 , (void*)0);
	int b = ft_printf("bjr %p %p\n", (void*)0 , (void*)0);

	printf("%d\n%d\n", a, b);
}*/
