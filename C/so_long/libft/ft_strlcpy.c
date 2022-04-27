/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:06:57 by izouf             #+#    #+#             */
/*   Updated: 2022/01/12 15:32:06 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	slen = ft_strlen(src);
	i = 0;
	if (slen + 1 < dstsize)
		while (i <= slen)
			dst[i++] = *src++;
	else if (dstsize)
	{
		while (i < dstsize - 1)
			dst[i++] = *src++;
		dst[i] = 0;
	}
	return (slen);
}
