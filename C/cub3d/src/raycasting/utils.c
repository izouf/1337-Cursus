/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:32:21 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/25 23:33:51 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	getcolor(t_texture *t, int x, int y)
{
	char	*ptr;
	int		pixel;

	pixel = y * t->line_l + x * 4;
	ptr = t->addr + pixel;
	return ((((unsigned char)ptr[2]) << 16)
		+ (((unsigned char)ptr[1]) << 8) + ((unsigned char)ptr[0]));
}

void	ft_swap(t_pair	**sprites, int amount)
{
	int		tmp1;
	float	tmp2;
	int		i;
	int		j;

	i = -1;
	while (++i < amount)
	{
		j = i - 1;
		while (++j < amount)
		{
			if (sprites[0][i].first > sprites[0][j].first)
			{
				tmp1 = sprites[0][i].first;
				sprites[0][i].first = sprites[0][j].first;
				sprites[0][j].first = tmp1;
				tmp2 = sprites[0][i].second;
				sprites[0][i].second = sprites[0][j].second;
				sprites[0][j].second = tmp2;
			}
		}
	}
}

float	ft_abs(float value)
{
	if (value < 0)
		return (-value);
	return (value);
}

static void	pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (x * (win->bpp / 8) + y * win->line_l);
	*(int *) dst = color;
}

void	ft_put(t_win *win, unsigned int **buffer)
{
	int	i;
	int	j;

	i = -1;
	while (++i < S_H)
	{
		j = -1;
		while (++j < S_W)
			pixel_put(win, j, i, buffer[i][j]);
	}
	i = -1;
	while (++i < S_H)
	{
		j = -1;
		while (++j < S_W)
			buffer[i][j] = 0;
	}
}
