/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:47:26 by tasargsy          #+#    #+#             */
/*   Updated: 2025/07/19 19:57:38 by tasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int num)
{
	size_t	bytes;

	bytes = 0;
	if (num > 9)
		bytes += ft_putnbr_unsigned(num / 10);
	bytes += ft_putchr(num % 10 + '0');
	return (bytes);
}
