/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 02:12:43 by tasargsy          #+#    #+#             */
/*   Updated: 2025/07/19 15:41:57 by tasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int signo, void *handler, bool use_siginfo)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	if (use_siginfo)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(signo, &sa, NULL) < 0)
	{
		ft_printf("Sigaction failed");
		exit(EXIT_FAILURE);
	}
}

void	ft_kill(pid_t pid, int signo)
{
	if (kill(pid, signo) < 0)
	{
		perror("ft_kill failed");
		exit(EXIT_FAILURE);
	}
}

void	*ft_memset(void *buff, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) buff;
	while (len--)
	{
		ptr[len] = (unsigned char) c;
	}
	return (buff);
}
