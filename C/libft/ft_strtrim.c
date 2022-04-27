/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:17:27 by izouf             #+#    #+#             */
/*   Updated: 2021/11/09 10:41:52 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	sep(char const *c, char const *charset)
{
	while (*charset)
	{
		if (*c == *charset++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1)
		return (NULL);
	while (*s1 && sep(s1, set))
		s1++;
	i = ft_strlen(s1) - 1;
	while (s1[i] && sep(s1 + i, set))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
