/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:56:05 by izouf             #+#    #+#             */
/*   Updated: 2022/01/12 19:08:59 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_check_move(t_game *game, char sprite)
{
	if (sprite == '0')
		return (0);
	if (sprite == '1')
		return (1);
	if (sprite == 'E')
	{
		if (game->coin->amount == 0)
			return (2);
		else
			return (1);
	}
	if (sprite == 'C')
	{
		game->coin->taken++;
		return (0);
	}
	return (3);
}

void	ft_move(t_game *game, int x, int y, int dir)
{
	int	r;

	r = ft_check_move(game, game->map->map[y][x]);
	if (!r)
	{
		game->player->p_step++;
		game->player->p_direction = dir;
		game->map->map[y][x] = 'P';
		game->map->map[game->player->player_y][game->player->player_x] = '0';
	}
	else if (r == 1)
	{
		game->player->p_direction = dir;
	}
	else if (r == 2)
	{
		ft_putendl_fd("YOU WIN \n", 1);
		ft_close(game);
	}
	else if (r == 3)
	{
		ft_putendl_fd("YOU LOSE \n", 1);
		ft_close(game);
	}
}
