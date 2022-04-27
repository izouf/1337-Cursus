/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herewego.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:58:59 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/26 11:48:08 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dda(t_raycast *ray, t_win *win, char **map, int x)
{
	ft_init_v(ray, x);
	ft_init_dist(ray);
	ft_wall_col(ray, map, win->bonus);
	ft_side(ray);
	ft_init_c(ray, x, win->bonus);
}

int	keyrelease(int keycode, t_key *key)
{
	if (keycode == 0)
		key->a = 0;
	if (keycode == 1)
		key->s = 0;
	if (keycode == 2)
		key->d = 0;
	if (keycode == 13)
		key->w = 0;
	if (keycode == 123)
		key->l = 0;
	if (keycode == 124)
		key->r = 0;
	return (0);
}

int	keypress(int keycode, t_key *key)
{
	if (keycode == 0)
		key->a = 1;
	if (keycode == 1)
		key->s = 1;
	if (keycode == 2)
		key->d = 1;
	if (keycode == 13)
		key->w = 1;
	if (keycode == 123)
		key->l = 1;
	if (keycode == 124)
		key->r = 1;
	if (keycode == 53)
		exit(1);
	return (0);
}

void	ft_print(t_raycast *ray, t_win *win, char **map, int bonus)
{
	int	x;

	win->img = mlx_new_image(win->mlx, S_W, S_H);
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_l, &win->en);
	if (bonus == 1)
	{
		win->mini.img = mlx_new_image(win->mlx, S_W / 5, S_H / 5);
		win->mini.addr = mlx_get_data_addr(win->mini.img, &win->mini.bpp,
				&win->mini.line_l, &win->mini.en);
	}
	x = -1;
	while (++x < S_W)
		ft_dda(ray, win, map, x);
	(bonus == 1 && ft_sprites(ray, map));
	ft_put(win, ray->buffer);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	(bonus == 1 && ft_minimap(ray, win, map) \
		&& mlx_put_image_to_window(win->mlx, win->win, win->mini.img, \
			S_W - S_W / 5, S_H - S_H / 5) \
		&& mlx_destroy_image(win->mlx, win->mini.img));
	mlx_destroy_image(win->mlx, win->img);
}

void	ft_herewego(t_game *game, t_cub parsing, int bonus)
{
	t_raycast	ray;
	t_win		win;

	ray.pic = 0;
	game->map = parsing.map;
	ft_init(&ray, parsing, game->map, bonus);
	ft_init_key(&game->key);
	win.bonus = bonus;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, S_W, S_H, "c3d");
	win.mini.height = S_H / 50;
	win.mini.width = S_W / 50;
	ft_load(&ray, win.mlx, parsing);
	ft_print(&ray, &win, game->map, bonus);
	game->ray = &ray;
	game->win = &win;
	mlx_hook(win.win, 2, (1L << 0), keypress, &game->key);
	mlx_hook(win.win, 3, (1L << 1), keyrelease, &game->key);
	mlx_hook(win.win, 17, 0, &ft_close, NULL);
	mlx_loop_hook(win.mlx, ft_move, game);
	if (bonus == 1)
		mlx_hook(win.win, 6, (1L << 6), ft_mouse, game);
	mlx_loop(win.mlx);
}
