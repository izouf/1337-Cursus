/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:39:53 by izouf             #+#    #+#             */
/*   Updated: 2022/01/12 18:50:12 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_check_bmove(char sprite)
{
	if (sprite == '0')
		return (0);
	if (sprite == '1' || sprite == 'E' || sprite == 'C'
		|| sprite == 'H' || sprite == 'F')
		return (1);
	return (3);
}

static void	ft_boss_move(t_game *game, int x, int y, int dir)
{
	int	r;

	r = ft_check_bmove(game->map->map[y][x]);
	if (!r)
	{
		game->boss->b_direction = dir;
		game->map->map[y][x] = 'F';
		game->map->map[game->boss->boss_y][game->boss->boss_x] = '0';
	}
	else if (r == 1)
		game->boss->b_direction = dir;
	if (r == 3)
	{
		ft_putendl_fd("YOU LOSE !\n", 1);
		ft_close(game);
	}
}

void	ft_boss(t_game *game)
{
	int	col;
	int	row;

	row = abs(game->boss->boss_y - game->player->player_y);
	col = abs(game->boss->boss_x - game->player->player_x);
	if (row <= 3 && col <= 3)
	{
		if (game->boss->boss_y > game->player->player_y)
			ft_boss_move(game, game->boss->boss_x, game->boss->boss_y - 1, 1);
		else if (game->boss->boss_y < game->player->player_y)
			ft_boss_move(game, game->boss->boss_x, game->boss->boss_y + 1, 0);
		else
		{
			if (game->boss->boss_x < game->player->player_x)
				ft_boss_move(game, game->boss->boss_x + 1,
					game->boss->boss_y, 2);
			else if (game->boss->boss_x > game->player->player_x)
				ft_boss_move(game, game->boss->boss_x - 1,
					game->boss->boss_y, 3);
		}
	}
}
