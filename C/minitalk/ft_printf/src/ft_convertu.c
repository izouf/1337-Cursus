/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:04:40 by izouf             #+#    #+#             */
/*   Updated: 2021/12/01 16:16:29 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_putnbru_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbru_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

int	ft_nbrlenu(unsigned int n)
{
	if (n < 10)
		return (1);
	return (1 + ft_nbrlenu(n / 10));
}

static void	ft_handleu_width(t_check *check, unsigned int n, int len, int diff)
{
	if (check->flag[e_0] == '1' && diff == 0)
	{
		if (check->point != 0)
			while (--check->width > len)
				ft_putchar_fd(' ', 1);
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
	}
	ft_putnchar_fd('0', diff, 1);
	if (check->point != 1 || n != 0)
		ft_putnbru_fd(n, 1);
}

static void	ft_handleu(t_check *check, unsigned int n, int len, int diff)
{
	if (check->flag[e_min] == '1')
	{
		ft_putnchar_fd('0', diff, 1);
		if ((check->point != 1) || n != 0)
			ft_putnbru_fd(n, 1);
		if (check->width > len)
			while (--check->width > len + diff)
				ft_putchar_fd(' ', 1);
	}
	else
	{
		if (check->width > len)
			ft_handleu_width(check, n, len, diff);
		else
		{
			ft_putnchar_fd('0', diff, 1);
			if (check->point != 1 || n != 0)
				ft_putnbru_fd(n, 1);
		}
	}
}

void	ft_convertu(t_check *check)
{
	unsigned int	n;
	int				len;
	int				diff;

	n = va_arg(check->args, unsigned int);
	len = ft_nbrlenu(n);
	diff = check->precision - len;
	if (check->point == 1 && n == 0)
		len--;
	if (diff < 0)
		diff = 0;
	if (check->width <= check->precision)
		check->f_len = check->f_len + diff;
	if (check->width > len && check->width > check->precision)
	{
		check->f_len = check->f_len + (check->width - len);
		check->width++;
	}
	ft_handleu(check, n, len, diff);
	check->f_len = check->f_len + len;
	check->str++;
}
