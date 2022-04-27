/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:34:13 by izouf             #+#    #+#             */
/*   Updated: 2022/01/12 19:19:04 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void	ft_switch(t_game *game, int y, int x, int move)
{
	if (!move)
	{
		game->map->map[y][x] = '0';
		game->map->map[y][x - 1] = 'H';
	}
	if (move == 1)
	{
		game->map->map[y][x] = '0';
		game->map->map[y][x + 1] = 'H';
	}
	if (move == 2)
	{
		game->map->map[y][x] = '0';
		game->map->map[y - 1][x] = 'H';
	}
	if (move == 3)
	{
		game->map->map[y][x] = '0';
		game->map->map[y + 1][x] = 'H';
	}
}

static int	ft_check_lose(t_game *game, int y, int x)
{
	if (game->map->map[y][x] == '0')
		return (0);
	if (game->map->map[y][x] == 'P')
	{
		ft_putendl_fd("YOU LOSE !\n", 1);
		ft_close(game);
	}
	return (1);
}

static void	ft_emove(t_game *game, int y, int x)
{
	int	r;

	r = rand() % 4;
	if (r == 0 && !ft_check_lose(game, y, x - 1))
		ft_switch(game, y, x, r);
	if (r == 1 && !ft_check_lose(game, y, x + 1))
		ft_switch(game, y, x, r);
	if (r == 2 && !ft_check_lose(game, y - 1, x))
		ft_switch(game, y, x, r);
	if (r == 3 && !ft_check_lose(game, y + 1, x))
		ft_switch(game, y, x, r);
	ft_print(game);
}

void	ft_enemy(t_game *game)
{
	static int	frame;
	int			y;
	int			x;

	frame++;
	if (frame == 50)
	{
		y = 0;
		while (y < game->map->height)
		{
			x = 0;
			while (x < game->map->width)
			{
				if (game->map->map[y][x] == 'H')
					ft_emove(game, y, x);
				x++;
			}
			y++;
		}
		frame = 0;
	}
}
