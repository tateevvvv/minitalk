/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:18:32 by tasargsy          #+#    #+#             */
/*   Updated: 2025/07/19 15:50:54 by tasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchr(char a);
int		ft_putstr(char *str);
int		ft_putnbr(int num);
int		ft_putnbr_unsigned(unsigned int num);
int		ft_put_hex(unsigned long long num, int up);
int		ft_put_hex_ptr(unsigned long long num);
int		ft_printf(const char *str, ...);
size_t	ft_formatter(const char *str, va_list args);

#endif