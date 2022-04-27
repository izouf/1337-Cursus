/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:26:32 by izouf             #+#    #+#             */
/*   Updated: 2022/01/12 19:06:09 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_border(t_game *game)
{
	if (!ft_check_line(game->map->map[0], "1", game->map->width)
		|| !ft_check_line(game->map->map[game->map->height - 1], "1",
			game->map->width))
		return (ft_putendl_fd("Wrong map !", 2), 0);
	if ((int)ft_strlen(game->map->map[game->map->height - 1])
		!= game->map->width)
		return (ft_putendl_fd("Wrong map !", 2), 0);
	return (1);
}

int	ft_check_obj(char *line, char obj)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (line && line[i])
	{
		if (line[i] == obj)
			c++;
		i++;
	}
	return (c);
}

int	ft_check_line(char *line, char *str, int width)
{
	int	i;

	i = 0;
	if (!line || !str)
		return (0);
	while (line[i] && i < width && ft_strchr(str, line[i]))
		i++;
	if (i == width)
		return (1);
	return (0);
}

void	ft_init_obj(t_obj *objs)
{
	objs->p = 0;
	objs->c = 0;
	objs->e = 0;
	objs->b = 0;
}

void	ft_draw(t_game *game, int *frame, int *i, char *img)
{
	mlx_put_image_to_window(game->vars->mlx, game->vars->win,
		img, game->exit->exit_x * 64, game->exit->exit_y * 64);
	(*frame)++;
	if (*frame == 10)
	{
		*frame = 0;
		(*i)++;
	}
	if (*i == 5)
		*i = 0;
}
