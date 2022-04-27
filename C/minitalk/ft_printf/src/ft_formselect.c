/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formselect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:24:11 by izouf             #+#    #+#             */
/*   Updated: 2021/11/30 14:33:15 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_formselect(t_check *check)
{
	if (*check->str == 'c')
		ft_convertc(check);
	else if (*check->str == 's')
		ft_converts(check);
	else if (*check->str == 'p')
		ft_convertp(check);
	else if (*check->str == 'd' || *check->str == 'i')
		ft_convertd(check);
	else if (*check->str == 'u')
		ft_convertu(check);
	else if (*check->str == 'x' || *check->str == 'X')
		ft_convertx(check);
	else if (*check->str == '%')
		ft_convertper(check);
}
