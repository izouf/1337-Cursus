/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:11:56 by izouf             #+#    #+#             */
/*   Updated: 2021/11/07 12:06:06 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < dstsize && *dst)
		dst++;
	if (i == dstsize)
		return (i + ft_strlen(src));
	j = -1;
	while (src[++j])
		if (j < dstsize - i - 1)
			*dst++ = src[j];
	*dst = 0;
	return (i + j);
}
