/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreffers <sreffers@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:08:40 by sreffers          #+#    #+#             */
/*   Updated: 2025/09/30 17:28:20 by sreffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	is_specifier(char c)
{
	int		i;
	char	*specifier;

	specifier = "cspdiuxX%";
	i = 0;
	while (specifier[i])
	{
		if (c == specifier[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd, count);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd, int *count)
{
	*count += write(fd, &c, 1);
}
