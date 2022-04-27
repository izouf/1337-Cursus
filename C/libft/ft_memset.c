/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:27:12 by izouf             #+#    #+#             */
/*   Updated: 2021/11/09 12:06:19 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{	
	size_t			i;
	unsigned char	*t;

	i = 0;
	t = (unsigned char *)b;
	while (len--)
		t[i++] = (unsigned char)c;
	return (b);
}
