/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:03:19 by izouf             #+#    #+#             */
/*   Updated: 2022/05/30 15:17:27 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	struct s_info	*info;
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;
	pthread_mutex_t	check;
	struct timeval	last_meal;
	int				n_meal;
}					t_philo;

typedef struct s_info
{
	int				nph;
	int				death_t;
	int				eat_t;
	int				sleep_t;
	int				m_eat;
	struct timeval	start_t;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	*fork;
	int				np_finish;
	int				finish;
	t_philo			*philo;
}					t_info;

int			ft_parse(int argc, char **argv, t_info *info);
int			ft_init(t_info *info);

void		*ft_activity(void *ph);
long long	ft_ms(struct timeval atm);
void		ft_print_status(t_philo *philo, char *str);

void		*ft_check_finish(void *data);
void		*ft_check_death(void *ph);
#endif
