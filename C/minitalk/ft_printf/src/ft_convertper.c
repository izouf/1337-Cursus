/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:16:25 by izouf             #+#    #+#             */
/*   Updated: 2021/11/30 19:09:00 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handleper_width(t_check *check)
{
	if (check->width > 1)
	{
		check->f_len = check->f_len + check->width - 1;
		check->width++;
		if (check->flag[e_0] == '1' && check->flag[e_min] != '1')
			while (--check->width > 1)
				ft_putchar_fd('0', 1);
		else
			while (--check->width > 1)
				ft_putchar_fd(' ', 1);
	}
}

void	ft_convertper(t_check *check)
{
	if (check->flag[e_min] == '1')
		ft_putchar_fd('%', 1);
	ft_handleper_width(check);
	if (check->flag[e_min] != '1')
		ft_putchar_fd('%', 1);
	check->f_len++;
	check->str++;
}
