/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:45:33 by izouf             #+#    #+#             */
/*   Updated: 2021/11/30 17:35:11 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handleswidth(t_check *check, int lenght)
{
	if (check->width > lenght)
	{
		check->f_len = check->f_len + (check->width - lenght);
		while (check->width > lenght)
		{
			ft_putchar_fd(' ', 1);
			check->width--;
		}
	}
}

void	ft_handles(t_check *check, char *str, int lenght)
{
	if (check->flag[e_min] == '1' && check->point != '1')
		ft_putstr_fd(str, 1);
	ft_handleswidth(check, lenght);
	if (check->flag[e_min] != '1' && check->point != '1')
		ft_putstr_fd(str, 1);
	check->f_len = check->f_len + lenght;
	check->str++;
	free (str);
}

void	ft_converts(t_check *check)
{
	char	*t;
	char	*tmp;
	int		lenght;

	tmp = va_arg(check->args, char *);
	if (tmp == NULL)
		tmp = "(null)";
	if (check->precision == 0 && check->point == 1)
		tmp = "";
	if (check->precision == 0)
		t = ft_strdup(tmp);
	else
	{
		t = ft_calloc((check->precision), sizeof(char));
		ft_strlcpy(t, tmp, (check->precision) + 1);
	}
	if (check->point != 1)
		lenght = ft_strlen(t);
	else
		lenght = 0;
	ft_handles(check, t, lenght);
}
