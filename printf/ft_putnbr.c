/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:44:53 by tasargsy          #+#    #+#             */
/*   Updated: 2025/07/19 19:56:37 by tasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	size_t	bytes;

	bytes = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		bytes += ft_putchr('-');
		num = -num;
	}
	if (num > 9)
		bytes += ft_putnbr(num / 10);
	bytes += ft_putchr((num % 10) + '0');
	return (bytes);
}
