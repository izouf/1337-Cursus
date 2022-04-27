/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:14:40 by izouf             #+#    #+#             */
/*   Updated: 2022/04/26 17:28:39 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define MANDATORY 0
# define BONUS 1
# define S_W 1280
# define S_H 720
# define T_W 64
# define T_H 64
# define FLOOR 0x00FF00
# define WALLS 0xDEB887
# define PLAYER 0x0000FF
# define DOOR 0xFFFFFF
# define BOWSER 0xDC143C
# define T1 "pics/1.xpm"
# define T2 "pics/2.xpm"
# define T3 "pics/3.xpm"
# define T4 "pics/4.xpm"
# define T5 "pics/5.xpm"
# define T6 "pics/6.xpm"
# define T7 "pics/7.xpm"
# define T8 "pics/8.xpm"
# define T9 "pics/9.xpm"
# define T10 "pics/10.xpm"
# define T11 "pics/11.xpm"
# define T12 "pics/12.xpm"
# define T13 "pics/13.xpm"
# define T14 "pics/14.xpm"
# define T15 "pics/15.xpm"
# define T16 "pics/toady.xpm"

typedef struct s_info
{
	char			*n;
	char			*s;
	char			*e;
	char			*w;
	char			*d;
	char			*c;
	char			*f;
	char			*s1;
	unsigned int	cc;
	unsigned int	fc;
	int				test[256];
}					t_info;

typedef struct s_cub
{
	char	**map;
	t_info	info;
}	t_cub;

typedef struct s_sprite
{
	float	x;
	float	y;
	int		text;
}	t_sprite;

typedef struct s_texture
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_l;
	int		en;
}	t_texture;

typedef struct s_parsing
{
	int		fd;
	int		index;
	int		counter;
	char	*tmpline;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor_red;
	int		floor_green;
	int		floor_blue;
	int		color_floor;
	int		ceiling_red;
	int		ceiling_green;
	int		ceiling_blue;
	int		color_ceiling;
	char	**argv;
	char	*first_line;
	char	**map;
	size_t	count_lines;
	size_t	biggest_lines;
	size_t	skip_lines;
}	t_parsing;

typedef struct s_pair
{
	int		first;
	float	second;
}	t_pair;

typedef struct s_raycast
{
	float			posx;
	float			posy;
	float			dirx;
	float			diry;
	float			planex;
	float			planey;
	float			camera;
	float			raydirx;
	float			raydiry;
	int				mapx;
	int				mapy;
	float			sidedistx;
	float			sidedisty;
	float			deltadistx;
	float			deltadisty;
	float			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	unsigned int	ceiling;
	unsigned int	floor;
	unsigned int	color;
	int				texnum;
	float			wallx;
	int				texx;
	int				texy;
	float			step;
	float			texpos;
	float			olddirx;
	float			oldplanex;
	float			movespeed;
	float			rotspeed;
	unsigned int	**buffer;
	float			*zbuffer;
	int				*sp_order;
	float			*sp_distance;
	int				amount;
	float			sprx;
	float			spry;
	float			invdet;
	float			transformx;
	float			transformy;
	int				sp_screen;
	int				sp_height;
	int				sp_width;
	int				draw_startx;
	int				draw_starty;
	int				draw_endx;
	int				draw_endy;
	int				m_screen;
	int				pic;
	t_sprite		*sprite;
	t_texture		t[20];
}	t_raycast;

typedef struct s_mimimap
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_l;
	int		en;
	int		i_start;
	int		i_end;
	int		j_start;
	int		j_end;
	int		height;
	int		width;
}	t_minimap;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bpp;
	int			line_l;
	int			en;
	int			bonus;
	t_minimap	mini;
}	t_win;

typedef struct s_key
{
	int	a;
	int	s;
	int	d;
	int	w;
	int	l;
	int	r;
}	t_key;

typedef struct s_game
{
	t_win		*win;
	t_raycast	*ray;
	t_key		key;
	char		**map;
}	t_game;

/*************************************************/

int				str_len(const char *s, char c);
void			free_tab(char **t);
int				count_world(const char *s, char c);
char			*str_cpy(const char *s, int size);
char			**ft_split(char *s, char c);
size_t			ft_strlen(char *s);
void			ft_concta(char *dest, char *src);
char			*ft_strjoin(int size, char **strs, char *sep);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strdup(const char *s);
int				ft_atoi(char *nptr);
int				check_file(char *t);
int				ft_strcmp(char *s1, char c);
char			*read_map(int fd);
int				cont_line(char *t);
void			ft_ifspace(char *line, int *i);
void			get_res(t_cub *all, char *line);
char			*check_texr(char *line, char *op);
void			ft_firstcheck(t_cub *all, char c);
unsigned int	get_rgb(char *line);
void			ft_parsing_line(t_cub *all, char *line, int i);
char			**fil_tab(int line, int fd, t_cub *all);
void			get_width_height(char **map, int *width, int *height);
int				ft_check_map_horizontal(char **map, int height);
int				ft_check_map_vertical(char **map, int width, int height);
void			ft_remplir_map(char **map, int width, int height);
void			ft_check(char **s);
void			ft_pars(t_cub *all, int width, int height);
void			big_parss1(t_cub *all, char c);
int				big_parss(int ac, char *av[], t_cub *all, char c);
void			check_b(t_cub *a);
void			check_charb(t_cub *a, char c);
void			check_m(t_cub *a);
void			check_charm(t_cub *a, char c);
int				ft_isdigit(char c);
void			if_digit(char *s);

/*************************************************/
void			*ft_memset(void *s, int c, size_t n);
void			replace_nl_with_null(char *str);
void			free_parsing(t_cub *parsing);
int				check_file_name(char *str);
int				skip_spaces(char *tmpline);
int				assign_floor(t_cub *parsing, int i);
int				assign_ceiling(t_cub *parsing, int i);
int				assign_vars_two(t_cub *parsing, int i);
int				assign_vars_three(t_cub *parsing, int i);
int				assign_vars(t_cub *parsing);
void			init_parsing(t_cub *parsing, char *argv[]);
void			parsing_directions_colors_two(t_cub *parsing);
int				parsing_directions_colors(t_cub *parsing, \
		char *argv[], int argc);
int				skip_newlines(t_cub *parsing);
void			parse_map(t_cub *parsing, size_t i);
int				check_fist_last_line(t_cub *parsing);
int				check_first_indexes(t_cub *parsing);
int				check_map(t_cub *parsing, int i, int j);
void			parse_map_assign_two(t_cub *parsing, size_t *i);
void			parse_map_assign(t_cub *parsing, size_t i);
void			replace_spc_wall(t_cub *parsing);
int				search_for_player(t_cub *parsing, int i, int j, int count);
int				search_for_player2(t_cub *parsing, int i, int j, int count);
void			ft_bzero(void *s, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
int				contains_newline(char const *s1);
char			*first_line(char *str);
char			*second_part(char *str);
char			*get_next_line(int fd);
int				check_colors(char *str);
void			main_parse(int ac, char **av, t_cub *parsing, int mode);

int				keypress(int keycode, t_key *key);
int				keyrelease(int keycode, t_key *key);
void			ft_herewego(t_game *game, t_cub parsing, int bonus);
void			ft_print(t_raycast *ray, t_win *win, char **map, int bonus);

void			ft_load(t_raycast *ray, void *mlx, t_cub parsing);
void			ft_init(t_raycast *ray, t_cub parsing, char **map, int bonus);

void			ft_init_key(t_key *key);
int				ft_nsprite(char **map);
void			ft_hitdoor(t_raycast *ray, char c);
void			ft_checkdoor(char **map, float x, float y);
int				ft_error(char *str);

unsigned int	getcolor(t_texture *t, int x, int y);
void			ft_swap(t_pair **sprites, int amount);
float			ft_abs(float value);
void			ft_put(t_win *win, unsigned int **buffer);

void			ft_init_v(t_raycast *ray, int x);
void			ft_init_dist(t_raycast *ray);
void			ft_wall_col(t_raycast *ray, char **map, int bonus);
void			ft_side(t_raycast *ray);
void			ft_init_c(t_raycast *ray, int x, int bonus);

int				ft_sprites(t_raycast *ray, char **map);

int				ft_move(t_game *game);

int				ft_mouse(int x, int y, t_game *game);

int				ft_minimap(t_raycast *ray, t_win *win, char **map);

void			ft_free(t_cub *parsing, t_game *game);
int				ft_close(void);

void			ft_frame(t_raycast *ray);

#endif
