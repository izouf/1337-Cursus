/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:27:27 by izouf             #+#    #+#             */
/*   Updated: 2021/11/12 10:27:51 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ts;
	unsigned char	*td;

	if (!dst && !src)
		return (NULL);
	ts = (unsigned char *)src;
	td = dst;
	while (n--)
		*td++ = *ts++;
	return (dst);
}
