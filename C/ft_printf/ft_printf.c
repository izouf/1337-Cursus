/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:21:01 by izouf             #+#    #+#             */
/*   Updated: 2021/11/30 18:46:11 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_check	*check;
	int		len;

	check = ft_calloc(1, sizeof(t_check));
	va_start(check->args, format);
	check->str = format;
	while (*check->str)
	{
		while (*check->str && *check->str != '%')
		{
			ft_putchar_fd(*check->str, 1);
			check->f_len++;
			check->str++;
		}
		if (*check->str && *check->str == '%')
			ft_herewego(check);
	}
	va_end(check->args);
	len = check->f_len;
	free (check);
	return (len);
}
