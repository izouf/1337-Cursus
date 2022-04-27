/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:39:28 by izouf             #+#    #+#             */
/*   Updated: 2021/11/04 16:17:29 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*t;

	t = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!t)
		return (NULL);
	ft_memcpy(t, s1, ft_strlen(s1));
	t[ft_strlen(s1)] = 0;
	return (t);
}
