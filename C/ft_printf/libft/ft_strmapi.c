/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:40:42 by izouf             #+#    #+#             */
/*   Updated: 2021/11/09 10:46:42 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*t;

	if (!s)
		return (NULL);
	t = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!t)
		return (NULL);
	i = -1;
	while (s[++i])
		t[i] = f(i, s[i]);
	t[i] = 0;
	return (t);
}
