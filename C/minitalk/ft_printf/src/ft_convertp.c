/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:51:06 by izouf             #+#    #+#             */
/*   Updated: 2021/12/01 15:45:47 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_nbrlenp(unsigned long n)
{
	if (n < 16)
		return (1);
	return (1 + ft_nbrlenp(n / 16));
}

static void	ft_puthex(unsigned long n)
{
	if (n > 15)
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
			ft_putchar_fd(n - 10 + 'a', 1);
	}
}

static void	ft_handlep(t_check *check, unsigned long n, int len, int diff)
{
	if (check->flag[e_min] == '1')
	{
		ft_putstr_fd("0x", 1);
		ft_putnchar_fd('0', diff, 1);
		if (!(check->point == 1 && n == 0))
			ft_puthex(n);
		if (check->width > len)
			while (--check->width > len + diff)
				ft_putchar_fd(' ', 1);
	}
	else
	{
		if (check->width > len && (check->flag[e_0] != '1'\
					|| check->point != 0))
			while (--check->width > len + diff)
				ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		if (check->width > len && (check->flag[e_0] != '1' \
					|| check->point == 0))
			while (--check->width > len + diff)
				ft_putchar_fd('0', 1);
		ft_putnchar_fd('0', diff, 1);
		if (!(check->point == 1 && n == 0))
			ft_puthex(n);
	}
}

void	ft_convertp(t_check *check)
{
	unsigned long	n;
	int				len;
	int				diff;

	n = va_arg(check->args, unsigned long);
	len = ft_nbrlenp(n);
	diff = check->precision - len;
	len += 2;
	if (diff < 0)
		diff = 0;
	if (check->point == 1 && n == 0)
		len--;
	if (check->width <= check->precision)
		check->f_len = check->f_len + diff;
	if (check->width > len && check->width > check->precision)
	{
		check->f_len = check->f_len + (check->width - len);
		check->width++;
	}
	ft_handlep(check, n, len, diff);
	check->f_len = check->f_len + len;
	check->str++;
}
