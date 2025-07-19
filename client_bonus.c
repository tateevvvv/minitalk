/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:35:39 by tasargsy          #+#    #+#             */
/*   Updated: 2025/07/19 15:52:55 by tasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_server = BUSY;

void	ack_handler(int signo)
{
	(void)signo;
	g_server = READY;
}

void	end_handler(int signo)
{
	(void)signo;
	write(1, "exav", 4);
	exit(EXIT_SUCCESS);
}

void	send_char(char c, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			ft_kill(server, SIGUSR1);
		else
			ft_kill(server, SIGUSR2);
		++bit;
		while (g_server == BUSY)
			usleep(420);
		g_server = BUSY;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Usage = ./server <PID> \"Message\"\n");
		exit(EXIT_FAILURE);
	}
	server = atoi(argv[1]);
	message = argv[2];
	ft_signal(SIGUSR1, ack_handler, false);
	ft_signal(SIGUSR2, end_handler, false);
	while (*message)
		send_char(*message++, server);
	send_char('\0', server);
	return (EXIT_SUCCESS);
}