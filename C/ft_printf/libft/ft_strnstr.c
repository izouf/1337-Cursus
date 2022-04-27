/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:40:25 by izouf             #+#    #+#             */
/*   Updated: 2021/11/09 10:43:17 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;

	if (!*n)
		return ((char *)h);
	while (*h && len)
	{
		if (*h == *n)
		{
			i = 1;
			while (n[i] && h[i] == n[i] && len >= ft_strlen(n))
				i++;
			if (!n[i])
				return ((char *)h);
		}
		h++;
		len--;
	}
	return (0);
}
