/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:54:49 by izouf             #+#    #+#             */
/*   Updated: 2022/03/04 13:55:07 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

	pthread_mutex_lock(&philo->info->finish_mutex);
	gettimeofday(&atm, NULL);
	ms = ft_ms(atm) - ft_ms(philo->info->start_t);
	if (!philo->info->finish)
		printf("%lld\t%d\t%s\n", ms, philo->id + 1, str);
	pthread_mutex_unlock(&philo->info->finish_mutex);
}

static void	ft_eat(t_philo *philo)
{
	long long	ms;

	pthread_mutex_lock(&philo->check);
	gettimeofday(&philo->last_meal, NULL);
	ms = ft_ms(philo->last_meal) - ft_ms(philo->info->start_t);
	pthread_mutex_lock(&philo->info->finish_mutex);
	if (!philo->info->finish)
		printf("%lld\t%d\t%s\n", ms, philo->id + 1, "Eating .....");
	philo->n_meal ++;
	if (philo->n_meal == philo->info->m_eat)
		philo->info->np_finish ++;
	pthread_mutex_unlock(&philo->info->finish_mutex);
	usleep(philo->info->eat_t * 1000);
	pthread_mutex_unlock(philo->rf);
	pthread_mutex_unlock(philo->lf);
	pthread_mutex_unlock(&philo->check);
}

void	*ft_activity(void *ph)
{
	t_philo	*philo;

	philo = ph;
	if (!(philo->id % 2))
		usleep(philo->info->eat_t * 1000);
	while (!philo->info->finish)
	{
		pthread_mutex_lock(philo->rf);
		ft_print_status(philo, "Has taken a fork");
		if (!philo->lf)
		{
			usleep(philo->info->death_t * 2000);
			return (NULL);
		}
		pthread_mutex_lock(philo->lf);
		ft_print_status(philo, "Has taken a fork");
		ft_eat(philo);
		ft_print_status(philo, "Sleeping .....");
		usleep(philo->info->sleep_t * 1000);
		ft_print_status(philo, "Thinking .....");
	}
	return (NULL);
}
