/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreffers <sreffers@student.42madrid.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:10:41 by sreffers          #+#    #+#             */
/*   Updated: 2025/09/30 17:19:44 by sreffers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		is_specifier(char c);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
int		ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd, int *count);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *count);
void	ft_putnbr_base(unsigned int nbr, char *base, int *count);
void	ft_putnbr_base_long(unsigned long nbr, char *base, int *count);
int		ft_printf(const char *str, ...);

#endif
