/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:39:44 by tasargsy          #+#    #+#             */
/*   Updated: 2025/03/04 17:40:54 by tasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	size_t	bytes;

	if (str == NULL)
		return (ft_putstr("(null)"));
	bytes = 0;
	while (*str)
		bytes += ft_putchr(*str++);
	return (bytes);
}
