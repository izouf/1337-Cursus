/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_clr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:19 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/26 16:36:46 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

void	check_charm(t_cub *a, char c)
{
	if (c != '1' && c != '0' && c != ' ' && c != 'N' && c != 'E'
		&& c != 'W' && c != 'S')
	{
		free(a->info.n);
		free(a->info.s);
		free(a->info.e);
		free(a->info.w);
		exit(printf("map error1"));
	}
}

void	check_m(t_cub *a)
{
	int	i;
	int	j;
	int	cp;

	i = -1;
	cp = 0;
	while (a->map[++i])
	{
		j = -1;
		while (a->map[i][++j])
		{
			check_charm(a, a->map[i][j]);
			if (a->map[i][j] == 'N' || a->map[i][j] == 'E'
				|| a->map[i][j] == 'W' || a->map[i][j] == 'S')
				cp++;
		}
	}
	if (cp != 1)
	{
		free(a->info.n);
		free(a->info.s);
		free(a->info.e);
		free(a->info.w);
		exit(printf("map error2"));
	}
}

void	check_charb(t_cub *a, char c)
{
	if (c != '1' && c != '0' && c != ' ' && c != 'N' && c != 'E'
		&& c != 'W' && c != 'S' && c != 'D' && c != 'F')
	{
		free(a->info.n);
		free(a->info.s);
		free(a->info.e);
		free(a->info.w);
		exit(printf("map error3"));
	}
}

void	check_b(t_cub *a)
{
	int	i;
	int	j;
	int	cp;

	i = -1;
	cp = 0;
	while (a->map[++i])
	{
		j = -1;
		while (a->map[i][++j])
		{
			check_charb(a, a->map[i][j]);
			if (a->map[i][j] == 'N' || a->map[i][j] == 'E'
				|| a->map[i][j] == 'W' || a->map[i][j] == 'S')
				cp++;
		}
	}
	if (cp != 1)
	{
		free(a->info.n);
		free(a->info.s);
		free(a->info.e);
		free(a->info.w);
		exit(printf("map error4"));
	}
}
