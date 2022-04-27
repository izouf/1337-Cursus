/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:12:58 by izouf             #+#    #+#             */
/*   Updated: 2022/04/26 11:43:25 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_v(t_raycast *ray, int x)
{
	ray->camera = 2 * x / (float)S_W - 1;
	ray->raydirx = ray->dirx + ray->planex * ray->camera;
	ray->raydiry = ray->diry + ray->planey * ray->camera;
	ray->mapx = (int)ray->posx;
	ray->mapy = (int)ray->posy;
	if (ray->raydirx == 0)
		ray->deltadistx = 1e30;
	else
		ray->deltadistx = ft_abs(1 / ray->raydirx);
	if (ray->raydiry == 0)
		ray->deltadisty = 1e30;
	else
		ray->deltadisty = ft_abs(1 / ray->raydiry);
}

void	ft_init_dist(t_raycast *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->posy) * ray->deltadisty;
	}
	ray->hit = 0;
}

void	ft_wall_col(t_raycast *ray, char **map, int bonus)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->texnum = 1;
			if (ray->raydirx > 0)
				ray->texnum = 0;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->texnum = 3;
			if (ray->raydiry > 0)
				ray->texnum = 2;
			ray->side = 1;
		}
		if (map[ray->mapx][ray->mapy] == '1')
			ray->hit = 1;
		if (bonus == 1)
			ft_hitdoor(ray, map[ray->mapx][ray->mapy]);
	}
}

void	ft_side(t_raycast *ray)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
	else
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
	ray->lineheight = (int)(S_H / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + S_H / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + S_H / 2;
	if (ray->drawend >= S_H)
		ray->drawend = S_H - 1;
	if (ray->side == 0)
		ray->wallx = ray->posy + ray->perpwalldist * ray->raydiry;
	else
		ray->wallx = ray->posx + ray->perpwalldist * ray->raydirx;
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (float)T_W);
	ray->step = 1.0 * T_H / ray->lineheight;
	ray->texpos = (ray->drawstart - S_H / 2 + ray->lineheight / 2) * ray->step;
}

void	ft_init_c(t_raycast *ray, int x, int bonus)
{
	int	y;

	y = 0;
	while (y < ray->drawstart)
		ray->buffer[y++][x] = ray->ceiling;
	while (y < ray->drawend)
	{
		ray->texy = (int)ray->texpos & (T_H - 1);
		ray->texpos += ray->step;
		ray->color = getcolor(&ray->t[ray->texnum], ray->texx, ray->texy);
		ray->buffer[y][x] = ray->color;
		y++;
	}
	while (y < S_H)
		ray->buffer[y++][x] = ray->floor;
	if (bonus == 1)
		ray->zbuffer[x] = ray->perpwalldist;
}
