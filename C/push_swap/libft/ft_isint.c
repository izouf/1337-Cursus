/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:08:39 by izouf             #+#    #+#             */
/*   Updated: 2021/12/22 17:56:59 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(const char *str)
{
	unsigned int	r;
	int				i;
	int				s;
	int				exist;

	r = 0;
	exist = 0;
	i = 0;
	s = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (ft_isdigit(str[i]) && ++exist)
	{
		if (r > 2147483647)
		{
			if (!(r == 2147483648 && s == -1))
				ft_error();
		}
		r = r * 10 + (str[i++] - '0');
	}
	return (!str[i] && exist);
}
