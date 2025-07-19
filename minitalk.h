/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 02:12:36 by tasargsy          #+#    #+#             */
/*   Updated: 2025/07/19 15:40:49 by tasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "printf/ft_printf.h"

enum
{
	READY,
	BUSY,
};

void	ft_signal(int, void *, bool);
void	ft_kill(pid_t, int);
void	ack_handler(int signo);
void	end_handler(int signo);
void	send_char(char c, pid_t server);
void	handler(int signo, siginfo_t *info, void *more_info);
void	*ft_memset(void *buff, int c, size_t len);

#endif