/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 07:41:47 by izouf             #+#    #+#             */
/*   Updated: 2022/03/04 17:09:45 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <semaphore.h>

typedef struct s_philo
{
	int				id;
	int				n_meal;
	char			*name;
	sem_t			*check;
	pid_t			pid;
	struct s_info	*info;
	struct timeval	last_meal;
}					t_philo;

typedef struct s_info
{
	int				nph;
	int				death_t;
	int				sleep_t;
	int				eat_t;
	int				m_eat;
	sem_t			*acting;
	sem_t			*np_finish;
	sem_t			*finish;
	sem_t			*fork;
	t_philo			*philo;
	struct timeval	start_t;
}					t_info;

int			ft_parse(int argc, char **argv, t_info *info);
int			ft_init(t_info *info);

void		ft_activity(t_philo *philo);
void		ft_print_status(t_philo *philo, char *str);
long long	ft_ms(struct timeval atm);

void		*ft_check_death(void *data);
void		*ft_check_finish(void *data);
void		*ft_stop(void *data);

char		*ft_make(char *name, int value);
#endif
