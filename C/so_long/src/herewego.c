/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herewego.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:36:27 by izouf             #+#    #+#             */
/*   Updated: 2022/01/12 18:59:47 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*ft_initialize(t_game *game, char *img, void *mlx, t_sprite *sprite)
{
	void	*p;

	p = mlx_xpm_file_to_image(mlx, img, &sprite->img_width,
			&sprite->img_height);
	if (!p)
	{
		ft_free_game(game);
		ft_putendl_fd("img Error !\n", 2);
		exit (1);
	}
	return (p);
}

static void	ft_init(t_game *game)
{
	game->vars = malloc(1 * sizeof(t_vars));
	game->player = malloc(1 * sizeof(t_player));
	game->boss = malloc(1 * sizeof(t_boss));
	game->coin = malloc(1 * sizeof(t_coin));
	game->sprite = malloc(1 * sizeof(t_sprite));
	game->exit = malloc(1 * sizeof(t_exit));
}

int	ft_load(t_game *game, t_vars *vars, t_sprite *sprite)
{
	sprite->wall = ft_initialize(game, WALL, vars->mlx, sprite);
	sprite->ground = ft_initialize(game, GROUND, vars->mlx, sprite);
	sprite->coin = ft_initialize(game, COIN, vars->mlx, sprite);
	sprite->enemy = ft_initialize(game, PIG, vars->mlx, sprite);
	sprite->player[0] = ft_initialize(game, PLAYER_D, vars->mlx, sprite);
	sprite->player[1] = ft_initialize(game, PLAYER_U, vars->mlx, sprite);
	sprite->player[2] = ft_initialize(game, PLAYER_R, vars->mlx, sprite);
	sprite->player[3] = ft_initialize(game, PLAYER_L, vars->mlx, sprite);
	sprite->boss[0] = ft_initialize(game, BOSS_D, vars->mlx, sprite);
	sprite->boss[1] = ft_initialize(game, BOSS_U, vars->mlx, sprite);
	sprite->boss[2] = ft_initialize(game, BOSS_R, vars->mlx, sprite);
	sprite->boss[3] = ft_initialize(game, BOSS_L, vars->mlx, sprite);
	sprite->exit[0] = ft_initialize(game, E_1, vars->mlx, sprite);
	sprite->exit[1] = ft_initialize(game, E_2, vars->mlx, sprite);
	sprite->exit[2] = ft_initialize(game, E_3, vars->mlx, sprite);
	sprite->exit[3] = ft_initialize(game, E_4, vars->mlx, sprite);
	sprite->exit[4] = ft_initialize(game, E_5, vars->mlx, sprite);
	return (1);
}

int	ft_herewego(t_game	*game)
{
	ft_init(game);
	if (!game->vars || !game->player || !game->boss
		|| !game->coin || !game->sprite || !game->exit)
		return (ft_free_game(game),
			ft_putendl_fd("Allocation game.map Failed !", 2), 0);
	game->vars->mlx = mlx_init();
	if (!game->vars->mlx)
		return (ft_free_game(game),
			ft_putendl_fd("Game start Failed !", 2), 0);
	game->vars->win = mlx_new_window(game->vars->mlx,
			game->map->width * 64, game->map->height * 64, "so_long");
	if (!game->vars->win)
		return (ft_free_game(game),
			ft_putendl_fd("Window Open Failed !", 2), 0);
	ft_load(game, game->vars, game->sprite);
	game->player->p_direction = 0;
	game->player->p_step = 0;
	game->boss->b_direction = 0;
	if (!ft_print(game))
		return (ft_free_game(game), 0);
	return (1);
}
