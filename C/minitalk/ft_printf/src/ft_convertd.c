/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:04:40 by izouf             #+#    #+#             */
/*   Updated: 2021/12/01 15:23:47 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_signflags(t_check *check, int n)
{
	if (n >= 0)
	{
		if (check->flag[e_space] == '1' && check->flag[e_plus] != '1')
			ft_putchar_fd(' ', 1);
		if (check->flag[e_plus] == '1')
			ft_putchar_fd('+', 1);
	}
	else
		ft_putchar_fd('-', 1);
}

int	ft_nbrlen(int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb < 10)
		return (1);
	return (1 + ft_nbrlen(nb / 10));
}

static void	ft_handled_width(t_check *check, int n, int len, int diff)
{
	if (check->flag[e_0] == '1' && diff == 0)
	{
		if (check->point != 0)
			while (--check->width > len)
				ft_putchar_fd(' ', 1);
		ft_signflags(check, n);
		if (check->point == 0)
			while (--check->width > len)
				ft_putchar_fd('0', 1);
	}
	else
	{
		if (check->flag[e_space] == '1' || check->flag[e_plus] == '1')
			check->width--;
		while (--check->width > (len + diff))
			ft_putchar_fd(' ', 1);
		ft_signflags(check, n);
	}
	ft_putnchar_fd('0', diff, 1);
	if (check->point != 1 || n != 0)
		ft_putnbr_fd(n, 1);
}

static void	ft_handled(t_check *check, int n, int len, int diff)
{
	if (check->flag[e_min] == '1')
	{
		ft_signflags(check, n);
		ft_putnchar_fd('0', diff, 1);
		if ((check->point != 1) || n != 0)
			ft_putnbr_fd(n, 1);
		if (check->width > len)
			while (--check->width > len + diff)
				ft_putchar_fd(' ', 1);
	}
	else
	{
		if (check->width > len)
			ft_handled_width(check, n, len, diff);
		else
		{
			ft_signflags(check, n);
			ft_putnchar_fd('0', diff, 1);
			if (check->point != 1 || n != 0)
				ft_putnbr_fd(n, 1);
		}
	}
}

void	ft_convertd(t_check *check)
{
	int	n;
	int	len;
	int	diff;

	n = va_arg(check->args, int);
	len = ft_nbrlen(n);
	diff = check->precision - len;
	if (check->point == 1 && n == 0)
		len--;
	if (n < 0)
		len++;
	else if (check->flag[e_plus] == '1' || check->flag[e_space] == '1')
		len++;
	if (diff < 0)
		diff = 0;
	if (check->width <= check->precision)
		check->f_len = check->f_len + diff;
	if (check->width > len && check->width > check->precision)
	{
		check->f_len = check->f_len + (check->width - len);
		check->width++;
	}
	ft_handled(check, n, len, diff);
	check->f_len = check->f_len + len;
	check->str++;
}
