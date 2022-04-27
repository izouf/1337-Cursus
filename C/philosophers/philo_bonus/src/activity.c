/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:23:43 by izouf             #+#    #+#             */
/*   Updated: 2022/03/04 14:02:51 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

long long	ft_ms(struct timeval atm)
{
	long long	ms;

	ms = atm.tv_sec * 1000 + atm.tv_usec / 1000;
	return (ms);
}

void	ft_print_status(t_philo *philo, char *str)
{
	long long		ms;
	struct timeval	atm;

	sem_wait(philo->info->acting);
	gettimeofday(&atm, NULL);
	ms = ft_ms(atm) - ft_ms(philo->info->start_t);
	printf("%lld\t%d\t%s\n", ms, philo->id + 1, str);
	sem_post(philo->info->acting);
}

static void	ft_eat(t_philo *philo)
{
	sem_wait(philo->check);
	gettimeofday(&philo->last_meal, NULL);
	ft_print_status(philo, "Eating .....");
	philo->n_meal ++;
	if (philo->n_meal == philo->info->m_eat)
		sem_post(philo->info->np_finish);
	usleep(philo->info->eat_t * 1000);
	sem_post(philo->info->fork);
	sem_post(philo->info->fork);
	sem_post(philo->check);
}

void	ft_activity(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, ft_check_death, philo);
	if (!(philo->id % 2))
		usleep(philo->info->eat_t * 1000);
	while (1)
	{
		sem_wait(philo->info->fork);
		ft_print_status(philo, "Has taken a fork");
		sem_wait(philo->info->fork);
		ft_print_status(philo, "Has taken a fork");
		ft_eat(philo);
		ft_print_status(philo, "Sleeping .....");
		usleep(philo->info->sleep_t * 1000);
		ft_print_status(philo, "Thinking .....");
	}
	exit(0);
}
