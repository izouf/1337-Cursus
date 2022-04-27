/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:18:21 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/26 11:12:58 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_sp(t_raycast *ray, int i, int x)
{
	int	stripe;
	int	y;
	int	d;

	stripe = ray->draw_startx - 1;
	while (++stripe < ray->draw_endx)
	{
		ray->texx = (int)(256 * (stripe - (-ray->sp_width / 2 \
		+ ray->sp_screen)) * T_W / ray->sp_width) / 256;
		if (ray->transformy > 0 && ray->transformy < ray->zbuffer[stripe])
		{
			y = ray->draw_starty - 1;
			while (++y < ray->draw_endy)
			{
				d = (y) * 256 - S_H * 128 + ray->sp_height * 128;
				ray->texy = ((d * T_H) / ray->sp_height) / 256;
				if (ray->sprite[ray->sp_order[i]].text == 10)
					x = 0;
				ray->color = getcolor(&ray->t[ray->sprite[ray->sp_order[i]].text
						+ x], ray->texx, ray->texy);
				if ((ray->color & 0x00FFFFFF) != 0)
					ray->buffer[y][stripe] = ray->color;
			}
		}
	}
}

static void	ft_calculate(t_raycast *ray, int i)
{
	ray->sprx = ray->sprite[ray->sp_order[i]].x - ray->posx;
	ray->spry = ray->sprite[ray->sp_order[i]].y - ray->posy;
	ray->invdet = 1.0 / (ray->planex * ray->diry - ray->dirx * ray->planey);
	ray->transformx = ray->invdet * (ray->diry * ray->sprx - ray->dirx \
	* ray->spry);
	ray->transformy = ray->invdet * (-ray->planey * ray->sprx \
	+ ray->planex * ray->spry);
	ray->sp_screen = (int)((S_W / 2) * (1 + ray->transformx / ray->transformy));
	ray->sp_height = abs((int)(S_H / ray->transformy)) / 1;
	ray->draw_starty = -ray->sp_height / 2 + S_H / 2;
	if (ray->draw_starty < 0)
		ray->draw_starty = 0;
	ray->draw_endy = ray->sp_height / 2 + S_H / 2;
	if (ray->draw_endy >= S_H)
		ray->draw_endy = S_H - 1;
	ray->sp_width = abs((int)(S_H / ray->transformy)) / 1;
	ray->draw_startx = -ray->sp_width / 2 + ray->sp_screen;
	if (ray->draw_startx < 0)
		ray->draw_startx = 0;
	ray->draw_endx = ray->sp_height / 2 + ray->sp_screen;
	if (ray->draw_endx >= S_W)
		ray->draw_endx = S_W;
}

static void	ft_sort_sp(int *order, float *dist, int amount)
{
	t_pair	*sprites;
	int		i;

	i = -1;
	sprites = malloc(amount * sizeof(t_pair));
	if (!sprites)
		ft_error("Allocation Error \n");
	while (++i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	ft_swap(&sprites, amount);
	i = -1;
	while (++i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
}

static void	ft_locate_sp(t_sprite **sprite, char **map)
{
	int	i;
	int	j;
	int	n;

	i = -1;
	n = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'F')
			{
				sprite[0][n].x = i + 0.5;
				sprite[0][n].y = j + 0.5;
				sprite[0][n].text = 4;
				n++;
			}
		}
	}
}

int	ft_sprites(t_raycast *ray, char **map)
{
	int	i;

	i = -1;
	ft_locate_sp(&ray->sprite, map);
	while (++i < ray->amount)
	{
		ray->sp_order[i] = i;
		ray->sp_distance[i] = (float)(pow(ray->posx - ray->sprite[i].x, 2) \
		- pow (ray->posy - ray->sprite[i].y, 2));
	}
	ft_sort_sp(ray->sp_order, ray->sp_distance, ray->amount);
	i = -1;
	while (++i < ray->amount)
	{
		ft_calculate(ray, i);
		ft_draw_sp(ray, i, ray->pic);
	}
	return (1);
}
