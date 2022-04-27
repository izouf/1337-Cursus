/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:24:58 by izouf             #+#    #+#             */
/*   Updated: 2022/01/19 18:05:45 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_msg(unsigned char c, int pid)
{
	int	ret;

	write(1, &c, 1);
	if (!c)
	{
		ft_printf("\n");
		ret = kill(pid, SIGUSR1);
		if (ret == -1)
		{
			ft_printf("kill error \n");
			exit(1);
		}
	}
}

void	ft_sig_handler(int sig, siginfo_t *info, void *unused)
{
	static unsigned char	c;
	static int				size;
	static int				pid;

	(void)unused;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		size = 0;
		c = 0;
	}
	if (sig == SIGUSR1)
		c += (1 << size);
	size++;
	if (size == 8)
	{
		ft_print_msg(c, pid);
		size = 0;
		c = 0;
	}
}

void	ft_sig_err(void)
{
	ft_printf("sigaction error\n");
	exit(1);
}

int	main(void)
{
	struct sigaction	talk;
	int					ret;

	ft_printf("Server PID : %d\n", getpid());
	talk.sa_sigaction = ft_sig_handler;
	talk.sa_flags = SA_SIGINFO;
	ret = sigaction(SIGUSR1, &talk, 0);
	if (ret == -1)
		ft_sig_err();
	ret = sigaction(SIGUSR2, &talk, 0);
	if (ret == -1)
		ft_sig_err();
	while (1)
		pause();
	return (0);
}
