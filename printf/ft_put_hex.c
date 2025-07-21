/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:25:28 by tasargsy          #+#    #+#             */
/*   Updated: 2025/03/04 17:37:21 by tasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long long num, int up)
{
	size_t	bytes;
	char	*digits;

	if (up)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	bytes = 0;
	if (num >= 16)
		bytes += ft_put_hex(num / 16, up);
	bytes += ft_putchr(digits[num % 16]);
	return (bytes);
}
