/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 02:12:36 by tasargsy          #+#    #+#             */
/*   Updated: 2025/07/19 20:20:17 by tasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/ft_printf.h"
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum
{
	READY,
	BUSY,
};

void	ft_signal(int signo, void *handler, bool use_siginfo);
void	ft_kill(pid_t pid, int signo);
void	ack_handler(int signo);
void	end_handler(int signo);
void	send_char(char c, pid_t server);
void	handler(int signo, siginfo_t *info, void *more_info);
void	*ft_memset(void *buff, int c, size_t len);
int		ft_atoi(const char *str);

#endif