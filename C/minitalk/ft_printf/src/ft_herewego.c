/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herewego.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:21:05 by izouf             #+#    #+#             */
/*   Updated: 2021/11/30 15:09:56 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_herewego(t_check *check)
{
	check->str++;
	ft_flags(check);
	ft_width(check);
	ft_precision(check);
	ft_formselect(check);
}
