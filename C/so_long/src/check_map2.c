/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:28:52 by izouf             #+#    #+#             */
/*   Updated: 2022/01/13 11:56:34 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_check_width(t_game *game, char *line)
{
	if (ft_check_line(line, "10ECPFH", game->map->width))
	{
		if (ft_check_line(line, "1", game->map->width))
		{
			if ((int)ft_strlen(line) == game->map->width)
				return (1);
		}
		if (line[0] != '1' || line[game->map->width - 1] != '1')
			return (ft_putendl_fd("Wrong Map !", 2), 0);
		if ((int)ft_strlen(line) - 1 != game->map->width)
			return (ft_putendl_fd("Wrong map !", 2), 0);
		return (1);
	}
	return (ft_putendl_fd("Wrong characters !", 2), 0);
}

static int	ft_checking(t_game *game, char **map, int *line, int i)
{
	map = ft_calloc(*line + 2, sizeof(char *));
	if (!map && game->map->map)
		return (ft_putendl_fd("Allocation game.map Failed !", 2), 0);
	map[*line] = get_next_line(game->map->fd);
	if (!map[*line])
	{
		if (!game->map->map)
			return (ft_putendl_fd("NULL characters -_- !", 2),
				free_tab(map), 0);
		return (free_tab(map), 1);
	}
	if (!game->map->width)
		game->map->width = ft_strlen(map[*line]) - 1;
	if (!ft_check_width(game, map[*line]))
		return (free_tab(map), 0);
	while (++i < *line)
		map[i] = ft_strdup(game->map->map[i]);
	if (game->map->map)
		free_tab(game->map->map);
	game->map->map = map;
	return (1);
}

static int	ft_validate_map(t_game *game)
{
	char	**map;
	int		line;
	t_obj	objs;

	line = 0;
	map = NULL;
	game->map->width = 0;
	ft_init_obj(&objs);
	while (!game->map->map || game->map->map[line - 1] || !line)
	{
		if (!ft_checking(game, map, &line, -1))
			return (0);
		objs.e += ft_check_obj(game->map->map[line], 'E');
		objs.c += ft_check_obj(game->map->map[line], 'C');
		objs.p += ft_check_obj(game->map->map[line], 'P');
		objs.b += ft_check_obj(game->map->map[line], 'F');
		line++;
	}
	if (objs.c < 1 || objs.p != 1 || objs.e < 1 || objs.b > 1)
		return (ft_putendl_fd("Wrong objects number !", 2), 0);
	game->map->height = line - 1;
	if (!ft_check_border(game))
		return (free_tab(game->map->map), 0);
	return (1);
}

static int	ft_check_file(char *file)
{
	int	len;

	len = (int)ft_strlen(file);
	if (file[len - 1] == 'r' && file[len - 2] == 'e'
		&& file[len - 3] == 'b' && file[len - 4] == '.')
		return (1);
	return (0);
}

int	ft_check_map(char *file, t_game *game)
{
	if (!ft_check_file(file))
		return (ft_putendl_fd("Support .ber files only!", 2), 0);
	game->map = malloc(1 * sizeof(t_map));
	if (!game->map)
		return (ft_putendl_fd("Allocation game.map Failed !", 2), 0);
	game->map->fd = open(file, O_RDONLY);
	if (game->map->fd == -1)
		return (free(game->map), ft_putendl_fd("File doesn't exist!", 2), 0);
	game->map->map = NULL;
	if (!ft_validate_map(game))
	{
		if (game->map->map)
			free_tab(game->map->map);
		return (0);
	}
	return (1);
}
