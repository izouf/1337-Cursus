/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:04:46 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/26 11:18:10 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put_mini(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->mini.addr + (x * (win->mini.bpp / 8) + y * win->mini.line_l);
	*(int *)dst = color;
}

void	ft_scale2(t_win *win, float x, float y, int color)
{
	int	i;
	int	j;

	x = (x - win->mini.j_start) * 10 - 5;
	y = (y - win->mini.i_start) * 10 - 5;
	i = x + 10;
	j = y + 10;
	while (y < j)
	{
		while (x < i)
			pixel_put_mini(win, x++, y, color);
		x -= 10;
		y++;
	}
}

void	ft_scale(t_win *win, float x, float y, int color)
{
	int	i;
	int	j;

	x = (x - win->mini.j_start) * 10;
	y = (y - win->mini.i_start) * 10;
	i = x + 10;
	j = y + 10;
	while (y < j - 1)
	{
		while (x < i - 1)
			pixel_put_mini(win, x++, y, color);
		x -= 9;
		y++;
	}
}

void	ft_minicolor(t_win *win, float x, float y, char c)
{
	if (c == '1')
		ft_scale(win, x, y, WALLS);
	if (c == '0' || c == 'O')
		ft_scale(win, x, y, FLOOR);
	if (c == 'F')
		ft_scale(win, x, y, BOWSER);
	if (c == 'D')
		ft_scale(win, x, y, DOOR);
}

int	ft_minimap(t_raycast *ray, t_win *win, char **map)
{
	int	i;
	int	j;

	i = ray->posx - win->mini.height / 2;
	if (i < 0)
		i = 0;
	win->mini.i_start = i;
	win->mini.i_end = i + win->mini.height;
	while (map[i] && i < win->mini.i_end)
	{
		j = ray->posy - win->mini.width / 2;
		if (j < 0)
			j = 0;
		win->mini.j_start = j;
		win->mini.j_end = j + win->mini.width;
		while (map[i][j] && j < win->mini.j_end)
		{
			ft_minicolor(win, (float)j, (float)i, map[i][j]);
			j++;
		}
		i++;
	}
	ft_scale2(win, ray->posy, ray->posx, PLAYER);
	return (1);
}
