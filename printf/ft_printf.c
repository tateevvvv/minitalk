/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:23:04 by tasargsy          #+#    #+#             */
/*   Updated: 2025/07/19 19:57:24 by tasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_formatter(const char *str, va_list args)
{
	size_t	bytes;

	bytes = 0;
	if (*str == '%')
		bytes += ft_putchr('%');
	else if (*str == 'c')
		bytes += ft_putchr(va_arg(args, int));
	else if (*str == 's')
		bytes += ft_putstr(va_arg(args, char *));
	else if (*str == 'p')
		bytes += ft_put_hex_ptr(va_arg(args, unsigned long long));
	else if (*str == 'i' || *str == 'd')
		bytes += ft_putnbr(va_arg(args, int));
	else if (*str == 'u')
		bytes += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*str == 'x')
		bytes += ft_put_hex(va_arg(args, unsigned int), 0);
	else if (*str == 'X')
		bytes += ft_put_hex(va_arg(args, unsigned int), 1);
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	size_t	bytes;
	va_list	args;

	bytes = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			bytes += ft_formatter(str++, args);
		}
		else
		{
			bytes += ft_putchr(*str);
			str++;
		}
	}
	va_end(args);
	return (bytes);
}
