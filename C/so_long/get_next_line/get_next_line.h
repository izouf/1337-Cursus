/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:01:43 by izouf             #+#    #+#             */
/*   Updated: 2022/01/05 10:39:51 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_read_line(int fd, char *str);
char	*get_next_line(int fd);
size_t	ft_gstrlen(char *s);
char	*ft_gstrchr(char *s, int c);
char	*ft_gstrjoin(char *s, char *buff);
char	*ft_alloc_line(char *s);
char	*ft_next_str(char *s);
#endif
