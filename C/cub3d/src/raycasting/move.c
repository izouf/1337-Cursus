/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:07:47 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/26 17:43:12 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_move1(t_raycast *ray, char **map, t_key key)
{
	if (key.w == 1)
	{
		if (map[(int)(ray->posx + ray->dirx * ray->movespeed)][(int)ray->posy] \
		== '0' || map[(int)(ray->posx + ray->dirx \
		* ray->movespeed)][(int)ray->posy] == 'O')
			ray->posx += ray->dirx * ray->movespeed;
		if (map[(int)ray->posx][(int)(ray->posy + ray->diry * ray->movespeed)] \
		== '0' || map[(int)ray->posx][(int)(ray->posy + ray->diry \
		* ray->movespeed)] == 'O')
			ray->posy += ray->diry * ray->movespeed;
	}
	if (key.a == 1)
	{
		if (map[(int)(ray->posx - ray->planex \
		* ray->movespeed)][(int)ray->posy] == '0' || map[(int)(ray->posx \
		- ray->planex * ray->movespeed)][(int)ray->posy] == 'O')
			ray->posx -= ray->planex * ray->movespeed;
		if (map[(int)ray->posx][(int)(ray->posy - ray->planey \
		* ray->movespeed)] == '0' || map[(int)ray->posx][(int)(ray->posy \
		- ray->planey * ray->movespeed)] == 'O')
			ray->posy -= ray->planey * ray->movespeed;
	}
}

static void	ft_move2(t_raycast *ray, char **map, t_key key)
{
	if (key.s == 1)
	{
		if (map[(int)(ray->posx - ray->dirx \
		* ray->movespeed)][(int)ray->posy] == '0' || map[(int)(ray->posx \
		- ray->dirx * ray->movespeed)][(int)ray->posy] == 'O')
			ray->posx -= ray->dirx * ray->movespeed;
		if (map[(int)ray->posx][(int)(ray->posy - ray->diry \
		* ray->movespeed)] == '0' || map[(int)ray->posx][(int)(ray->posy \
		- ray->diry * ray->movespeed)] == 'O')
			ray->posy -= ray->diry * ray->movespeed;
	}
	if (key.d == 1)
	{
		if (map[(int)(ray->posx + ray->planex \
		* ray->movespeed)][(int)ray->posy] == '0' || map[(int)(ray->posx \
		+ ray->planex * ray->movespeed)][(int)ray->posy] == 'O')
			ray->posx += ray->planex * ray->movespeed;
		if (map[(int)ray->posx][(int)(ray->posy + ray->planey \
		* ray->movespeed)] == '0' || map[(int)ray->posx][(int)(ray->posy \
		+ ray->planey * ray->movespeed)] == 'O')
			ray->posy += ray->planey * ray->movespeed;
	}
}

static void	ft_move3(t_raycast *ray, t_key key)
{
	if (key.r == 1)
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

static void	ft_move4(t_raycast *ray, t_key key)
{
	if (key.l == 1)
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

int	ft_move(t_game *game)
{
	t_raycast	*ray;
	t_win		*win;

	game->ray->movespeed = 0.1;
	game->ray->rotspeed = 0.03;
	ray = game->ray;
	win = game->win;
	mlx_clear_window(win->mlx, win->win);
	ft_move1(ray, game->map, game->key);
	ft_move2(ray, game->map, game->key);
	ft_move3(ray, game->key);
	ft_move4(ray, game->key);
	ft_checkdoor(game->map, game->ray->posx, game->ray->posy);
	ft_frame(ray);
	ft_print(game->ray, game->win, game->map, game->win->bonus);
	return (0);
}
