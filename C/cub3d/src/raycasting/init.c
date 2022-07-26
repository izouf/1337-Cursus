/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:00:20 by momayaz           #+#    #+#             */
/*   Updated: 2022/07/26 17:31:43 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_initialise(void *mlx, t_texture *t, char *img)
{
	int	img_w;
	int	img_h;

	t->img = mlx_xpm_file_to_image(mlx, img, &img_w, &img_h);
	if (!t->img)
		ft_error("Empty Xpm !\n");
	t->addr = mlx_get_data_addr(t->img, &t->bpp, &t->line_l, &t->en);
}

void	ft_load(t_raycast *ray, void *mlx, t_cub parsing)
{
	ray->ceiling = parsing.info.cc;
	ray->floor = parsing.info.fc;
	ft_initialise(mlx, &ray->t[0], parsing.info.n);
	ft_initialise(mlx, &ray->t[1], parsing.info.s);
	ft_initialise(mlx, &ray->t[2], parsing.info.w);
	ft_initialise(mlx, &ray->t[3], parsing.info.e);
	ft_initialise(mlx, &ray->t[4], T1);
	ft_initialise(mlx, &ray->t[5], T2);
	ft_initialise(mlx, &ray->t[6], T3);
	ft_initialise(mlx, &ray->t[7], T4);
	ft_initialise(mlx, &ray->t[8], T5);
	ft_initialise(mlx, &ray->t[9], T6);
	ft_initialise(mlx, &ray->t[10], T7);
	ft_initialise(mlx, &ray->t[11], T8);
	ft_initialise(mlx, &ray->t[12], T9);
	ft_initialise(mlx, &ray->t[13], T10);
	ft_initialise(mlx, &ray->t[14], T11);
	ft_initialise(mlx, &ray->t[15], T12);
	ft_initialise(mlx, &ray->t[16], T13);
	ft_initialise(mlx, &ray->t[17], T14);
	ft_initialise(mlx, &ray->t[18], T15);
	ft_initialise(mlx, &ray->t[19], T16);
	ray->sprite = malloc(ray->amount * sizeof(t_sprite));
	(!ray->sprite && ft_error("Allocation Error ! \n"));
	ray->pic = 0;
}

static void	ft_init_d(t_raycast **ray, char c)
{
	if (c == 'N' || c == 'S')
	{
		ray[0]->dirx = 1;
		ray[0]->diry = 0;
		ray[0]->planex = 0;
		ray[0]->planey = -0.40;
		if (c == 'N')
		{
			ray[0]->dirx = -1;
			ray[0]->planey = 0.4;
		}
	}
	if (c == 'E' || c == 'W')
	{
		ray[0]->dirx = 0;
		ray[0]->diry = 1;
		ray[0]->planex = 0.4;
		ray[0]->planey = 0;
		if (c == 'W')
		{
			ray[0]->diry = -1;
			ray[0]->planex = -0.4;
		}
	}
}

static void	ft_init_p(char **map, float *x, float *y, char *c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' \
			|| map[i][j] == 'W')
			{
				*x = (float)i;
				*y = (float)j;
				*c = map[i][j];
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	ft_init(t_raycast *ray, t_cub parsing, char **map, int bonus)
{
	char	c;
	int		i;

	ft_init_p(parsing.map, &ray->posx, &ray->posy, &c);
	ft_init_d(&ray, c);
	i = -1;
	ray->buffer = malloc(sizeof(unsigned int *) * S_H);
	(!ray->buffer && ft_error("error\n"));
	while (++i < S_H)
	{
		ray->buffer[i] = malloc (sizeof(unsigned int) * S_W);
		(!ray->buffer[i] && ft_error("error\n"));
	}
	if (bonus == 1)
	{
		ray->amount = ft_nsprite(map);
		ray->zbuffer = malloc (S_W * sizeof(float));
		(!ray->zbuffer && ft_error("Error allocation! \n"));
		ray->sp_order = malloc (ray->amount * sizeof(int));
		(!ray->sp_order && ft_error("Error allocation! \n"));
		ray->sp_distance = malloc (ray->amount * sizeof(float));
		(!ray->sp_distance && ft_error("Error allocation! \n"));
	}
}
