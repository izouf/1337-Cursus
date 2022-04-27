/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:33:59 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/26 11:33:18 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_key(t_key *key)
{
	key->s = 0;
	key->d = 0;
	key->w = 0;
	key->l = 0;
	key->r = 0;
	key->a = 0;
}

int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	ft_checkdoor(char **map, float x, float y)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'D' && (ft_abs(i - x) <= 2 && ft_abs(j - y) <= 2))
				map[i][j] = 'O';
			if (map[i][j] == 'O' && (ft_abs(i - x) >= 3 || ft_abs(j - y) >= 3))
				map[i][j] = 'D';
		}
	}
}

void	ft_hitdoor(t_raycast *ray, char c)
{
	if (c == 'D')
	{
		ray->hit = 1;
		ray->texnum = 19;
	}
}

int	ft_nsprite(char **map)
{
	int	i;
	int	j;
	int	cp;

	cp = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'F')
				cp++;
		}
	}
	return (cp);
}
