/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:49:04 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/26 15:48:41 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

unsigned int	get_rgb(char *line)
{
	int				i;
	int				j;
	char			**s;
	unsigned int	c;

	i = 0;
	s = ft_split(line, ' ');
	while (s[1][i] && s[1][i] != ',')
		i++;
	i++;
	if (!s[1][i] || s[1][i] == ',' || s[1][i] == '\n')
		exit(printf("rgb error"));
	j = i + 1;
	while (s[1][j] && s[1][j] != ',')
		j++;
	j++;
	if (!s[1][j] || s[1][j] == ',' || s[1][j] == '\n')
		exit(printf("rgb error"));
	c = (ft_atoi(s[1]) * 65536) + (ft_atoi(s[1] + i) * 256) + ft_atoi(s[1] + j);
	ft_check(s);
	j = 0;
	while (s[j])
		free(s[j++]);
	free(s);
	return (c);
}

void	ft_parsing_line(t_cub *all, char *line, int i)
{
	ft_ifspace(line, &i);
	ft_firstcheck(all, line[i]);
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		all->info.n = check_texr(line, "NO");
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		all->info.s = check_texr(line, "SO");
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		all->info.w = check_texr(line, "WE");
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		all->info.e = check_texr(line, "EA");
	else if (line[i] == 'F' && line[i + 1] == ' ')
		all->info.fc = get_rgb(line);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		all->info.cc = get_rgb(line);
	else if (line[i] && line != '\0' && line[i] != '1')
	{
		printf("pars error");
		exit(1);
	}
}

void	fil_tab2(char **t, int line, int fd, t_cub *all)
{
	int		i;
	int		j;
	char	*s;
	char	*s1;

	i = 0;
	j = 0;
	while ((i + j) < line)
	{
		s = read_map(fd);
		s1 = ft_strtrim(s, " ");
		if (s1[0] != '1')
		{
			ft_parsing_line(all, s1, 0);
			i++;
			free(s1);
			free(s);
			continue ;
		}
		ft_parsing_line(all, s1, 0);
		t[j] = s;
		j++;
		free(s1);
	}
	t[j] = 0;
}

char	**fil_tab(int line, int fd, t_cub *all)
{
	int		i;
	char	**t;
	int		j;

	i = 0;
	j = 0;
	t = malloc((line + 1) * sizeof(char *));
	if (!t)
		ft_error("Allocation failed !\n");
	fil_tab2(t, line, fd, all);
	return (t);
}

void	get_width_height(char **map, int *width, int *height)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (*width < (int)ft_strlen(map[i]))
			*width = ft_strlen(map[i]);
		i++;
	}
	*height = i;
}
