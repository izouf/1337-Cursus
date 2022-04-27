/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:39:56 by izouf             #+#    #+#             */
/*   Updated: 2021/11/30 18:34:14 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_hash(t_check *check, unsigned int n)
{
	if (check->flag[e_hash] == '1' && n != 0)
	{
		if (*check->str == 'x')
			ft_putstr_fd("0x", 1);
		else if (*check->str == 'X')
			ft_putstr_fd("0X", 1);
	}
}

int	ft_nbrlenx(unsigned int n)
{
	if (n < 16)
		return (1);
	return (1 + ft_nbrlenx(n / 16));
}

static void	ft_puthex(size_t n, char str)
{
	if (n > 15)
	{
		ft_puthex(n / 16, str);
		ft_puthex(n % 16, str);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
		{
			if (str == 'x')
				ft_putchar_fd(n - 10 + 'a', 1);
			else if (str == 'X')
				ft_putchar_fd(n - 10 + 'A', 1);
		}
	}
}

static void	ft_handlex(t_check *check, unsigned int n, int len, int diff)
{
	if (check->flag[e_min] == '1')
	{
		ft_hash(check, n);
		ft_putnchar_fd('0', diff, 1);
		if ((check->point != 1) || n != 0)
			ft_puthex(n, *check->str);
		if (check->width > len)
			while (--check->width > len + diff)
				ft_putchar_fd(' ', 1);
	}
	else
	{
		if (check->width > len && (check->flag[e_0] != '1'\
					||check->point != 0))
			while (--check->width > len + diff)
				ft_putchar_fd(' ', 1);
		ft_hash(check, n);
		if (check->width > len && (check->flag[e_0] != '1' \
					|| check->point == 0))
			while (--check->width > len + diff)
				ft_putchar_fd('0', 1);
		ft_putnchar_fd('0', diff, 1);
		if (check->point != 1 || n != 0)
			ft_puthex(n, *check->str);
	}
}

void	ft_convertx(t_check	*check)
{
	size_t	n;
	int		len;
	int		diff;

	n = va_arg(check->args, int);
	len = ft_nbrlenx(n);
	diff = check->precision - len;
	if (check->flag[e_hash] == '1' && n != 0)
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
	ft_handlex(check, n, len, diff);
	check->f_len = check->f_len + len;
	check->str++;
}
