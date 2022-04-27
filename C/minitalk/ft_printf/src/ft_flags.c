/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:42:13 by izouf             #+#    #+#             */
/*   Updated: 2021/11/26 17:51:03 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_flags(t_check *check)
{
	check->flag[e_min] = '0';
	check->flag[e_0] = '0';
	check->flag[e_hash] = '0';
	check->flag[e_space] = '0';
	check->flag[e_plus] = '0';
	while (*check->str == '-' || *check->str == '0' \
			|| *check->str == '#' || *check->str == ' ' || *check->str == '+')
	{
		if (*check->str == '-')
			check->flag[e_min] = '1';
		if (*check->str == '0')
			check->flag[e_0] = '1';
		if (*check->str == '#')
			check->flag[e_hash] = '1';
		if (*check->str == ' ')
			check->flag[e_space] = '1';
		if (*check->str == '+')
			check->flag[e_plus] = '1';
		check->str++;
	}
}
