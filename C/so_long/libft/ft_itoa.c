/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:04:05 by izouf             #+#    #+#             */
/*   Updated: 2021/11/09 11:00:44 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	nbrlen(unsigned int n)
{
	if (n < 10)
		return (1);
	return (1 + nbrlen(n / 10));
}

unsigned int	number(int n, int *i)
{
	unsigned int	nb;

	if (n < 0)
	{
		*i = 1;
		nb = -n;
	}
	else
		nb = n;
	return (nb);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	nb;
	char			*t;
	char			*base;

	base = "0123456789";
	i = 0;
	nb = number(n, &i);
	i += nbrlen(nb);
	t = malloc ((i + 1) * sizeof (char));
	if (!t)
		return (NULL);
	t[i] = 0;
	while (i--)
	{
		t[i] = base[nb % 10];
		nb /= 10;
	}
	if (n < 0)
		t[0] = '-';
	return (t);
}
