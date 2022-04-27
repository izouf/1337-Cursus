/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:27:59 by izouf             #+#    #+#             */
/*   Updated: 2021/12/01 15:10:43 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_width(t_check *check)
{
	check->width = 0;
	if (*check->str == '*')
	{
		check->width = va_arg(check->args, int);
		if (check->width < 0)
		{
			check->width = -(check->width);
			check->flag[e_min] = '1';
		}
		check->str++;
	}
	if (ft_isdigit(*check->str))
		check->width = ft_atoi(check->str);
	while (ft_isdigit(*check->str))
		check->str++;
}
