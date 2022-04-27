/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:09:31 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 12:16:11 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

int	countlen(int size, char **strs, char *sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
		j += ft_strlen(strs[i++]);
	if (size > 0)
		j += ft_strlen(sep) * (size - 1);
	return (j);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*t;
	int		i;
	int		j;

	j = countlen(size, strs, sep);
	t = malloc((j + 1) * sizeof(char));
	if (!t)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		ft_strcpy(t + j, strs[i]);
		j += ft_strlen(strs[i]);
		if (++i < size)
		{
			ft_strcpy(t + j, sep);
			j += ft_strlen(sep);
		}
	}
	t[j] = 0;
	return (t);
}
