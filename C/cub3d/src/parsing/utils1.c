/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:10:03 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/26 17:44:09 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*t;
	char	*src;

	src = (char *) s;
	i = ft_strlen(src);
	t = malloc((i + 1) * sizeof(char));
	if (t == NULL)
		ft_error("Allocation Failed \n");
	i = 0;
	while (src[i])
	{
		t[i] = src[i];
		i++;
	}
	t[i] = 0;
	return (t);
}

int	ft_atoi(char *nptr)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	if_digit(nptr);
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		ft_error("rgb error\n");
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			b = -b;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		a = a * 10 + *nptr - 48;
		nptr++;
	}
	a *= b;
	if (a < 0 || a > 255)
		exit(printf("rgb error"));
	return (a * b);
}

int	check_file(char *t)
{
	int		i;
	int		fd;
	char	c;
	int		r;

	i = 0;
	fd = open(t, O_RDWR);
	if (fd < 0)
		ft_error("file not found\n");
	r = read(fd, &c, 1);
	while (t[i])
		i++;
	i--;
	if (!(t[i] == 'b' && t[i - 1] == 'u' && t[i - 2] == 'c' && t[i - 3] == '.'))
		ft_error("file map must be .cub extension.\n");
	if (r <= 0)
		ft_error("empty file");
	return (1);
}

int	ft_strcmp(char *s1, char c)
{
	while (*s1 && *s1 == c)
		s1++;
	if (*s1)
		return (1);
	return (0);
}

char	*read_map(int fd)
{
	int		r;
	char	c;
	char	t[800000];
	int		i;

	r = 1;
	i = 0;
	while (read(fd, &c, 1))
	{
		t[i++] = c;
		if (c == '\n')
			break ;
	}
	t[i] = 0;
	return (ft_strdup(t));
}
