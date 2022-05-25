/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 07:51:49 by izouf             #+#    #+#             */
/*   Updated: 2022/05/25 10:12:38 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	ft_join(t_info *info)
{
	int	i;
	int	status;

	i = -1;
	while (++i < info->nph)
	{
		waitpid(info->philo[i].pid, &status, 0);
		sem_close(info->philo[i].check);
		free(info->philo[i].name);
	}
	free(info->philo);
	sem_close(info->acting);
	sem_close(info->fork);
	sem_close(info->finish);
}

static void	ft_fork(t_info *info)
{
	int	i;

	i = -1;
	gettimeofday(&info->start_t, NULL);
	while (++i < info->nph)
	{
		info->philo[i].last_meal = info->start_t;
		info->philo[i].pid = fork();
		if (!info->philo[i].pid)
			return (ft_activity(&info->philo[i]));
		else if (info->philo[i].pid < 0)
		{
			printf("Fork Failed ! \n");
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	t_info		info;
	pthread_t	thread;

	if (!ft_parse(argc, argv, &info))
		return (printf("Wrong Args !\n"), 0);
	info.philo = malloc(sizeof(t_philo) * info.nph);
	if (!info.philo)
		return (printf("Allocation Failed !\n"), 0);
	ft_init(&info);
	ft_fork(&info);
	if (info.m_eat)
		pthread_create(&thread, NULL, ft_check_finish, &info);
	pthread_create(&thread, NULL, ft_stop, &info);	
	ft_join(&info);
	return (0);
}
