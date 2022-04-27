/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:15:50 by izouf             #+#    #+#             */
/*   Updated: 2022/01/19 18:05:43 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_success(int sig)
{
	(void) sig;
	ft_printf("Data received \n");
	exit (0);
}

void	ft_msg(int pid, int c)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < 8)
	{
		usleep(300);
		if ((c >> i) & 1)
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		if (ret == -1)
		{
			ft_printf("wrong pid\n");
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = -1;
	if (argc != 3)
		return (ft_printf("Args error"));
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Wrong PID !");
		exit (1);
	}
	signal(SIGUSR1, ft_success);
	while (argv[2][++i])
		ft_msg(pid, argv[2][i]);
	ft_msg(pid, argv[2][i]);
	while (1)
		pause();
	exit(0);
	return (0);
}
