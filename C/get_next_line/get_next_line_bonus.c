/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:02:02 by izouf             #+#    #+#             */
/*   Updated: 2021/12/11 10:40:56 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *str)
{
	char	*buff;
	int		r;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	r = 1;
	while (!ft_strchr(str, '\n') && r != 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[r] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4096)
		return (0);
	str[fd] = ft_read_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_alloc_line(str[fd]);
	str[fd] = ft_next_str(str[fd]);
	return (line);
}
