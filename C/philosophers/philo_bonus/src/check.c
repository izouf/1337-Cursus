/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:36:17 by izouf             #+#    #+#             */
/*   Updated: 2022/03/04 16:59:03 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_make(char *name, int value)
{
	char	*res;
	int		i;
	int		n;

	n = value;
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	res = malloc(sizeof(char) * (i + ft_strlen(name) + 1));
	if (res == NULL)
		return (NULL);
	n = -1;
	while (++n < i)
		res[n] = name[n];
	while (value)
	{
		res[i++] = value % 10 + '0';
		value /= 10;
	}
	res[i] = 0;
	return (res);
}

void	*ft_stop(void *data)
{
	int		i;
	t_info	*info;

	i = -1;
	info = data;
	sem_wait(info->finish);
	while (++i < info->nph)
		kill(info->philo[i].pid, SIGTERM);
	return (NULL);
}

void	*ft_check_finish(void *data)
{
	t_info	*info;
	int		i;

	i = -1;
	info = data;
	while (++i < info->nph)
		sem_wait(info->np_finish);
	sem_post(info->finish);
	sem_close(info->np_finish);
	return (NULL);
}

void	*ft_check_death(void *data)
{
	t_philo			*philo;
	struct timeval	atm;
	long long		ms;

	philo = data;
	while (1)
	{
		sem_wait(philo->check);
		sem_wait(philo->info->acting);
		gettimeofday(&atm, NULL);
		ms = ft_ms(atm) - ft_ms(philo->last_meal);
		gettimeofday(&atm, NULL);
		if (ms >= philo->info->death_t)
		{
			printf("%lld\t%d\t%s\n", ft_ms(atm) - ft_ms(philo->info->start_t),
				philo->id + 1, "is Dead !");
			sem_post(philo->info->finish);
			return (NULL);
		}
		sem_post(philo->info->acting);
		sem_post(philo->check);
	}
	return (NULL);
}
