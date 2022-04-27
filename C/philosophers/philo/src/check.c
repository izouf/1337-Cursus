/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:26:30 by izouf             #+#    #+#             */
/*   Updated: 2022/03/01 14:59:57 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_check_finish(void *data)
{
	t_info	*info;

	info = data;
	while (!info->finish)
	{
		pthread_mutex_lock(&info->finish_mutex);
		if (info->np_finish == info->nph)
			info->finish = 1;
		pthread_mutex_unlock(&info->finish_mutex);
	}
	return (NULL);
}

void	*ft_check_death(void *ph)
{
	t_philo			*philo;
	struct timeval	atm;
	long long		ms;

	philo = ph;
	while (!philo->info->finish)
	{
		pthread_mutex_lock(&philo->check);
		pthread_mutex_lock(&philo->info->finish_mutex);
		gettimeofday(&atm, NULL);
		ms = ft_ms(atm) - ft_ms(philo->last_meal);
		gettimeofday(&atm, NULL);
		if (ms >= philo->info->death_t + 5 && !philo->info->finish)
		{
			printf("%lld\t%d\t%s\n", ft_ms(atm) - ft_ms(philo->info->start_t),
				philo->id + 1, "is Dead !");
			philo->info->finish = 1;
		}
		pthread_mutex_unlock(&philo->info->finish_mutex);
		pthread_mutex_unlock(&philo->check);
	}
	return (NULL);
}
