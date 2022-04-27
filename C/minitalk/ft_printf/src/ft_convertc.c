/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:49:18 by izouf             #+#    #+#             */
/*   Updated: 2021/11/30 15:24:11 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handlec_width(t_check *check)
{
	if (check->width > 1)
	{
		check->f_len = check->f_len + (check->width - 1);
		check->width++;
		while (--check->width > 1)
			ft_putchar_fd(' ', 1);
	}
}

void	ft_convertc(t_check *check)
{
	char	c;

	c = va_arg(check->args, int);
	if (check->flag[e_min] == '1')
		ft_putchar_fd(c, 1);
	handlec_width(check);
	if (check->flag[e_min] != '1')
		ft_putchar_fd(c, 1);
	check->f_len++;
	check->str++;
}
