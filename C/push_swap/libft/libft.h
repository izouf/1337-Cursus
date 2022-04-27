/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:20:19 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 18:15:09 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include	<stdlib.h>
# include	<unistd.h>

size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
void		ft_error(void);
char		*ft_strjoin(int size, char **strs, char *sep);
size_t		ft_max(size_t a, size_t b);
int			ft_isint(const char *str);
void		ft_putendl_fd(char *s, int fd);
void		*ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strdup(const char *s1);
char		*get_next_line(int fd);
int			ft_strcmp(char *s1, char *s2);
void		*free_tab(char **tab);

#endif
