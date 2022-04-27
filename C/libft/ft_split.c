/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:39:51 by izouf             #+#    #+#             */
/*   Updated: 2021/11/09 18:11:11 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	wordlen(char const *str, char c)
{
	int	i;

	i = 0;
	while (*str && *str++ != c)
		i++;
	return (i);
}

int	countword(char const *str, char c)
{
	int	r;
	int	w;

	w = 0;
	r = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		w = wordlen(str, c);
		str += w;
		if (w)
			r++;
	}
	return (r);
}

char	*wordcpy(char const *str, int size)
{
	char	*t;

	t = malloc((size + 1) * sizeof(char));
	if (!t)
		return (NULL);
	t[size] = 0;
	while (size--)
		t[size] = str[size];
	return (t);
}

void	*free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**t;
	int		size;
	int		i;
	int		l;

	if (!s)
		return (NULL);
	i = -1;
	l = countword(s, c);
	t = (char **)malloc((l + 1) * sizeof(char *));
	if (!t)
		return (NULL);
	while (++i < l)
	{
		while (*s && *s == c)
			s++;
		size = wordlen(s, c);
		t[i] = wordcpy(s, size);
		if (!t[i])
			return (free_tab(t));
		s += size;
	}
	t[i] = 0;
	return (t);
}
