/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:19:48 by izouf             #+#    #+#             */
/*   Updated: 2022/03/04 13:59:41 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *str)
{
	int		i;
	size_t	r;

	i = -1;
	r = 0;
	while (str[++i])
		r = r * 10 + (str[i] - 48);
	return (r);
}

int	ft_isnum(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
		}
	}
	return (1);
}

int	ft_parse(int argc, char **argv, t_info *info)
{
	if ((argc == 5 || argc == 6) && ft_isnum(argv))
	{
		info->nph = ft_atoi(argv[1]);
		info->death_t = ft_atoi(argv[2]);
		info->eat_t = ft_atoi(argv[3]);
		info->sleep_t = ft_atoi(argv[4]);
		info->m_eat = 0;
		if (argc == 6)
			info->m_eat = ft_atoi(argv[5]);
		if (info->nph <= 0 || info->death_t <= 0 || info->eat_t <= 0
			|| info->sleep_t <= 0 || (info->m_eat && info->m_eat <= 0))
			return (0);
		return (1);
	}
	return (0);
}

int	ft_init(t_info *info)
{
	int	i;

	i = -1;
	info->finish = 0;
	info->np_finish = 0;
	pthread_mutex_init(&info->finish_mutex, NULL);
	while (++i < info->nph)
	{
		info->philo[i].id = i;
		pthread_mutex_init(&info->fork[i], NULL);
		pthread_mutex_init(&info->philo[i].check, NULL);
		if (info->nph != 1)
		{
			if (!i)
				info->philo[i].lf = &info->fork[info->nph - 1];
			else
				info->philo[i].lf = &info->fork[i - 1];
		}
		else
			info->philo[i].lf = NULL;
		info->philo[i].rf = &info->fork[i];
		info->philo[i].info = info;
	}
	return (0);
}
