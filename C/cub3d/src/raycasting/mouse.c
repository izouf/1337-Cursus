/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:05:58 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/26 10:30:02 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_left(t_raycast *ray, int x, int pos)
{
	if (x > pos)
	{
		ray->olddirx = ray->dirx;
		ray->dirx = ray->dirx * cos(-ray->rotspeed) - ray->diry \
		* sin(-ray->rotspeed);
		ray->diry = ray->olddirx * sin(-ray->rotspeed) + ray->diry \
		* cos(-ray->rotspeed);
		ray->oldplanex = ray->planex;
		ray->planex = ray->planex * cos(-ray->rotspeed) - ray->planey \
		* sin(-ray->rotspeed);
		ray->planey = ray->oldplanex * sin(-ray->rotspeed) + ray->planey \
		* cos(-ray->rotspeed);
	}
}

static void	ft_right(t_raycast *ray, int x, int pos)
{
	if (x < pos)
	{
		ray->olddirx = ray->dirx;
		ray->dirx = ray->dirx * cos(ray->rotspeed) - ray->diry \
		* sin(ray->rotspeed);
		ray->diry = ray->olddirx * sin(ray->rotspeed) + ray->diry \
		* cos(ray->rotspeed);
		ray->olddirx = ray->planex;
		ray->planex = ray->planex * cos(ray->rotspeed) - ray->planey \
		* sin(ray->rotspeed);
		ray->planey = ray->olddirx * sin(ray->rotspeed) + ray->planey \
		* cos(ray->rotspeed);
	}
}

int	ft_mouse(int x, int y, t_game *game)
{
	static int	pos;

	mlx_clear_window(game->win->mlx, game->win->win);
	ft_left(game->ray, x, pos);
	ft_right(game->ray, x, pos);
	pos = x;
	ft_print(game->ray, game->win, game->map, game->win->bonus);
	return (y);
}

void	ft_frame(t_raycast *ray)
{
	static int	frame;
	static int	i;

	if (frame <= 2)
	{
		frame++;
		if (frame == 2)
		{
			frame = 0;
			i++;
			ray->pic = i;
		}
		if (i == 14)
			i = 0;
	}
}
