/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:03:35 by izouf             #+#    #+#             */
/*   Updated: 2022/01/13 11:25:20 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_close(game);
	else if (keycode == 2 || keycode == 124)
		ft_move(game, game->player->player_x + 1, game->player->player_y, 2);
	else if (keycode == 0 || keycode == 123)
		ft_move(game, game->player->player_x - 1, game->player->player_y, 3);
	else if (keycode == 1 || keycode == 125)
		ft_move(game, game->player->player_x, game->player->player_y + 1, 0);
	else if (keycode == 13 || keycode == 126)
		ft_move(game, game->player->player_x, game->player->player_y - 1, 1);
	ft_boss(game);
	ft_print(game);
	ft_putnbr_fd(game->player->p_step, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

static int	ft_exit(t_game *game)
{
	static int	frame;
	static int	i;

	if (frame < 20 && !i)
		ft_draw(game, &frame, &i, game->sprite->exit[0]);
	if (frame < 20 && i == 1)
		ft_draw(game, &frame, &i, game->sprite->exit[1]);
	if (frame < 20 && i == 2)
		ft_draw(game, &frame, &i, game->sprite->exit[2]);
	if (frame < 20 && i == 3)
		ft_draw(game, &frame, &i, game->sprite->exit[3]);
	if (frame < 20 && i == 4)
		ft_draw(game, &frame, &i, game->sprite->exit[4]);
	return (0);
}

static void	ft_flag(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'E')
			{
				game->exit->exit_y = y;
				game->exit->exit_x = x;
				ft_exit(game);
			}
			x++;
		}
		y++;
	}
}

static int	ft_steps(t_game *game)
{
	char	*str;
	char	*step;
	int		i;

	i = 0;
	if (!game->coin->amount)
		ft_flag(game);
	ft_enemy(game);
	step = ft_itoa(game->player->p_step);
	str = ft_strjoin("STEPS:  ", step);
	mlx_string_put(game->vars->mlx, game->vars->win, 8, 18, 0x00FFFFFF, str);
	free(str);
	free(step);
	return (0);
}

void	ft_hook(t_game *game)
{
	ft_putnbr_fd(game->player->p_step, 1);
	ft_putchar_fd('\n', 1);
	mlx_key_hook(game->vars->win, key_hook, game);
	mlx_loop_hook(game->vars->mlx, ft_steps, game);
	mlx_hook(game->vars->win, 17, 0, ft_close, game);
}
