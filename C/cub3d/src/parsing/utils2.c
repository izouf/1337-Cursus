/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:11:17 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/26 17:27:38 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

int	cont_line(char *t)
{
	int		fd;
	int		i;
	char	c;

	i = 0;
	fd = open(t, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			i++;
	}
	close(fd);
	return (++i);
}

void	ft_ifspace(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
		|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
}

void	ft_printf(char *op)
{
	printf("%s texture not found\n", op);
	exit(1);
}

char	*check_texr(char *line, char *op)
{
	int		j;
	char	**s;
	char	*text;
	int		fd;

	s = ft_split(line, ' ');
	if (!s)
		ft_printf(op);
	text = ft_strtrim(s[1], " \n");
	fd = open(text, O_RDONLY);
	if (fd == -1)
		ft_printf(op);
	close(fd);
	if (s[2] && s[2][0] != '\n')
		ft_printf(op);
	j = 0;
	while (s[j])
		free(s[j++]);
	free(s);
	return (text);
}

void	ft_firstcheck(t_cub *all, char c)
{
	if (all->info.test[(int)c] == 0)
		all->info.test[(int)c] += 1;
	else if (c && c != '1')
	{
		printf("double symbol %c ", c);
		exit(1);
	}
	if (c == '1')
	{
		if (!(all->info.test[(int) 'N'] == 1 && all->info.test[(int) 'W'] == 1
				&& all->info.test[(int) 'E'] == 1 && all->info.test[(int) 'S']
				== 1 && all->info.test[(int) 'F'] == 1
				&& all->info.test[(int) 'C'] == 1))
		{
			printf("map error1");
			exit(1);
		}
	}
	if (c != '1' && c != '0' && (all->info.test[(int) '1'] == 1))
	{
		printf("map error");
		exit(1);
	}
}
