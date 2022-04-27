/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:08:59 by momayaz           #+#    #+#             */
/*   Updated: 2022/04/26 15:46:30 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_concta(char *dest, char *src)
{
	int	i;
	int	dest_size;

	i = 0;
	dest_size = 0;
	while (dest[dest_size])
		dest_size++;
	while (src[i])
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		lenght;
	int		i;
	char	*concat;

	if (size > 0)
		lenght = ft_strlen(sep) * (size - 1);
	i = 0;
	while (i < size)
	{
		lenght += ft_strlen(strs[i]);
		i++;
	}
	concat = malloc(sizeof(char) * (lenght + 1));
	if (!concat)
		ft_error("Allocation Failed \n");
	i = 0;
	*concat = 0;
	while (i < size)
	{
		ft_concta(concat, strs[i]);
		if (i < size - 1)
			ft_concta(concat, sep);
		i++;
	}
	return (concat);
}

static int	is_trim(char const a, char const *b)
{
	while (*b)
	{
		if (a == *b)
			return (1);
		b++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*pt;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	while (*s1 && is_trim(*s1, set))
		s1++;
	if (!*s1)
	{
		pt = malloc(1 * sizeof(char));
		return (pt[0] = 0, pt);
	}
	while (s1[i])
		i++;
	while (is_trim(s1[i - 1], set))
		i--;
	pt = malloc(i + 1 * sizeof (char));
	if (!pt)
		ft_error("Allocation Failed \n");
	pt[i] = 0;
	while (--i >= 0)
		pt[i] = s1[i];
	return (pt);
}
