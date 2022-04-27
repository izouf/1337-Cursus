/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 09:11:46 by izouf             #+#    #+#             */
/*   Updated: 2021/11/30 18:53:14 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

enum		e_flags
{
	e_min,
	e_0,
	e_hash,
	e_space,
	e_plus,
};
typedef struct s_check
{
	const char	*str;
	va_list		args;
	int			width;
	int			precision;
	char		flag[5];
	int			f_len;
	int			point;
}				t_check;
void			ft_herewego(t_check *check);
void			ft_formselect(t_check *check);
void			ft_convertc(t_check *check);
void			ft_converts(t_check *check);
void			ft_convertd(t_check *check);
void			ft_convertu(t_check *check);
void			ft_convertx(t_check *check);
void			ft_convertp(t_check *check);
void			ft_convertper(t_check *check);
void			ft_flags(t_check *check);
void			ft_precision(t_check *check);
void			ft_width(t_check *check);
int				ft_printf(const char *format, ...);
void			ft_putnchar_fd(char c, int n, int fd);
#endif
