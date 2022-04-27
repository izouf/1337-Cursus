/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:45:21 by izouf             #+#    #+#             */
/*   Updated: 2022/01/13 09:58:06 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "mlx.h"

# define GROUND "./img/ground.xpm"
# define WALL "./img/wall.xpm"
# define EXIT "./img/exit.xpm"
# define COIN "./img/coin.xpm"
# define PLAYER_D "./img/p_down.xpm"
# define PLAYER_U "./img/p_up.xpm"
# define PLAYER_L "./img/p_left.xpm"
# define PLAYER_R "./img/p_right.xpm"
# define BOSS_D "./img/b_down.xpm"
# define BOSS_U "./img/b_up.xpm"
# define BOSS_L "./img/b_left.xpm"
# define BOSS_R "./img/b_right.xpm"
# define PIG "./img/enemy.xpm"
# define E_1 "./img/exit.xpm"
# define E_2 "./img/E_2.xpm"
# define E_3 "./img/E_3.xpm"
# define E_4 "./img/E_4.xpm"
# define E_5 "./img/E_5.xpm"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_player
{
	int		player_x;
	int		player_y;
	int		p_direction;
	int		p_step;
}				t_player;

typedef struct s_boss
{
	int		boss_x;
	int		boss_y;
	int		b_direction;
}				t_boss;

typedef struct s_exit
{
	int	exit_x;
	int	exit_y;
}				t_exit;

typedef struct s_coin
{
	int	amount;
	int	taken;
}				t_coin;

typedef struct s_sprite
{
	void	*wall;
	void	*ground;
	void	*coin;
	void	*exit[5];
	void	*enemy;
	void	*player[4];
	void	*boss[4];
	int		img_width;
	int		img_height;
}				t_sprite;

typedef struct s_map
{
	char	**map;
	int		fd;
	int		width;
	int		height;
	int		col;
	int		row;
}				t_map;

typedef struct s_game
{
	t_vars		*vars;
	t_map		*map;
	t_player	*player;
	t_coin		*coin;
	t_sprite	*sprite;
	t_exit		*exit;
	t_boss		*boss;
}				t_game;

typedef struct s_obj
{
	int	p;
	int	c;
	int	e;
	int	b;
}				t_obj;

int		ft_check_map(char *file, t_game *game);

int		ft_check_border(t_game *game);
int		ft_check_obj(char *line, char obj);
void	ft_init_obj(t_obj *obj);
int		ft_check_line(char *line, char *str, int width);
void	ft_draw(t_game *game, int *frame, int *i, char *img);

void	free_ptr(void **ptr);
void	free_tab(char **tab);
void	ft_free_game(t_game *game);

int		ft_herewego(t_game *game);
int		ft_print(t_game *game);

void	ft_hook(t_game *game);
void	ft_move(t_game *game, int x, int y, int dir);
void	ft_enemy(t_game *game);
void	ft_boss(t_game *game);

void	ft_mapclear(t_map *map);
void	ft_close_win(t_game *game);
int		ft_close(t_game *game);

#endif
