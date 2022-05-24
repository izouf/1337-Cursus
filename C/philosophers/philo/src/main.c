/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:14:37 by izouf             #+#    #+#             */
/*   Updated: 2022/05/24 09:55:36 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"
static void	ft_join(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nph)
	{
		pthread_join(info->philo[i].thread, NULL);
		pthread_mutex_destroy(&info->philo[i++].check);
	}
	free(info->philo);
	i = 0;
	while (i < info->nph)
		pthread_mutex_destroy(&info->fork[i++]);
	free(info->fork);
}

static void	ft_create(t_info *info)
{
	int			i;
	pthread_t	thread;

	i = -1;
	gettimeofday(&info->start_t, NULL);
	while (++i < info->nph)
	{
		info->philo[i].last_meal = info->start_t;
		pthread_create(&info->philo[i].thread, NULL, ft_activity,
			&info->philo[i]);
		pthread_create(&thread, NULL, ft_check_death, &info->philo[i]);
		pthread_detach(thread);
	}
	if (info->m_eat != 0)
	{
		pthread_create(&thread, NULL, ft_check_finish, info);
		pthread_detach(thread);
	}
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!ft_parse(argc, argv, &info))
		return (printf("Wrong Args !\n"), 0);
	info.philo = malloc(sizeof(t_philo) * info.nph);
	info.fork = malloc(sizeof(pthread_mutex_t) * info.nph);
	if (!info.philo || !info.fork)
		return (printf("Allocation Failed !\n"), 0);
	ft_init(&info);
	ft_create(&info);
	ft_join(&info);
	printf("Hello\n");
	return (0);
}
