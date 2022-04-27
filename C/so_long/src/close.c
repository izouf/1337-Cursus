/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:07:26 by izouf             #+#    #+#             */
/*   Updated: 2022/01/13 12:43:50 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_mapclear(t_map *map)
{
	close(map->fd);
	while (map->height--)
		free_ptr((void **)&map->map[map->height]);
	free_ptr((void **)&map->map);
	free_ptr((void **)&map);
}

void	ft_close_win(t_game *game)
{
	int	i;

	i = -1;
	mlx_destroy_image(game->vars->mlx, game->sprite->coin);
	mlx_destroy_image(game->vars->mlx, game->sprite->wall);
	mlx_destroy_image(game->vars->mlx, game->sprite->ground);
	mlx_destroy_image(game->vars->mlx, game->sprite->enemy);
	while (++i < 5)
		mlx_destroy_image(game->vars->mlx, game->sprite->exit[i]);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(game->vars->mlx, game->sprite->player[i]);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(game->vars->mlx, game->sprite->boss[i]);
	free_ptr((void **)&game->sprite);
	mlx_destroy_window(game->vars->mlx, game->vars->win);
	free_ptr((void **)&game->vars->mlx);
	free_ptr((void **)&game->vars);
}

int	ft_close(t_game *game)
{
	ft_close_win(game);
	ft_mapclear(game->map);
	free_ptr((void **)&game->player);
	free_ptr((void **)&game->coin);
	free_ptr((void **)&game->exit);
	free_ptr((void **)&game->boss);
	free_ptr((void **)&game);
	exit(0);
	return (0);
}
