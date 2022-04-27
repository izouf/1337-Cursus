/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:01:05 by izouf             #+#    #+#             */
/*   Updated: 2022/01/12 19:17:13 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_put_img(t_game *game, void *sprite)
{
	mlx_put_image_to_window(game->vars->mlx, game->vars->win,
		sprite, game->map->col * 64, game->map->row * 64);
}

static void	ft_put_player(t_game *game)
{
	ft_put_img(game, game->sprite->player[game->player->p_direction]);
	game->player->player_x = game->map->col;
	game->player->player_y = game->map->row;
}

static void	ft_put_boss(t_game *game)
{
	ft_put_img(game, game->sprite->boss[game->boss->b_direction]);
	game->boss->boss_x = game->map->col;
	game->boss->boss_y = game->map->row;
}

int	ft_select(char *line, t_game *game)
{
	if (line[game->map->col] == '0')
		ft_put_img(game, game->sprite->ground);
	else if (line[game->map->col] == '1')
		ft_put_img(game, game->sprite->wall);
	else if (line[game->map->col] == 'E')
	{
		ft_put_img(game, game->sprite->exit[0]);
		game->exit->exit_x = game->map->col;
		game->exit->exit_y = game->map->row;
	}
	else if (line[game->map->col] == 'C')
	{
		game->coin->amount++;
		ft_put_img(game, game->sprite->coin);
	}
	else if (line[game->map->col] == 'P')
		ft_put_player(game);
	else if (line[game->map->col] == 'H')
		ft_put_img(game, game->sprite->enemy);
	else if (line[game->map->col] == 'F')
		ft_put_boss(game);
	else
		return (0);
	return (1);
}

int	ft_print(t_game *game)
{
	game->map->row = 0;
	game->coin->amount = 0;
	while (game->map->row < game->map->height)
	{
		game->map->col = 0;
		while (game->map->col < game->map->width)
		{
			if (!ft_select(game->map->map[game->map->row], game))
				return (ft_putendl_fd("Sprite not found !", 2), 0);
			game->map->col++;
		}
		game->map->row++;
	}
	return (1);
}
