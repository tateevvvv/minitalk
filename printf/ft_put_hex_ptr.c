/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:36:36 by tasargsy          #+#    #+#             */
/*   Updated: 2025/07/19 19:56:21 by tasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_ptr(unsigned long long num)
{
	size_t	bytes;

	bytes = 0;
	if (!num)
	{
		bytes += ft_putstr("0x0");
		return (bytes);
	}
	bytes += ft_putstr("0x");
	bytes += ft_put_hex(num, 0);
	return (bytes);
}
