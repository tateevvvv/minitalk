/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 02:12:16 by tasargsy          #+#    #+#             */
/*   Updated: 2025/07/19 14:44:21 by tasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signo, siginfo_t *info, void *more_info)
{
	static char		c;
	static int		bit;
	static pid_t	client;

	(void)more_info;
	if (info->si_pid)
		client = info->si_pid;
	if (SIGUSR1 == signo)
		c |= (0x80 >> bit);
	else if (SIGUSR2 == signo)
		c &= ~(0x80 >> bit);
	++bit;
	if (bit == CHAR_BIT)
	{
		bit = 0;
		if (c == '\0')
		{
			write(1, "\n", 1);
			ft_kill(client, SIGUSR2);
			return ;
		}
		write(1, &c, 1);
	}
	ft_kill(client, SIGUSR1);
}

int	main(void)
{
	ft_printf("server PID = %d\n", getpid());
	ft_signal(SIGUSR1, handler, true);
	ft_signal(SIGUSR2, handler, true);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
