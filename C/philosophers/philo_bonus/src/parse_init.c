/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:51:23 by izouf             #+#    #+#             */
/*   Updated: 2022/03/04 17:27:27 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static sem_t	*ft_sem_init(char const *name, unsigned int value)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (sem != SEM_FAILED)
		return (sem);
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

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
	info->finish = ft_sem_init("finish", 0);
	info->acting = ft_sem_init("acting", 1);
	info->fork = ft_sem_init("fork", info->nph);
	info->np_finish = ft_sem_init("np_finish", 0);
	while (++i < info->nph)
	{
		info->philo[i].n_meal = 0;
		info->philo[i].name = ft_make("philo", i);
		info->philo[i].check = ft_sem_init(info->philo[i].name, 1);
		info->philo[i].id = i;
		info->philo[i].info = info;
	}
	return (0);
}
