/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:41:20 by izouf             #+#    #+#             */
/*   Updated: 2021/11/10 17:51:42 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*c;

	if (!lst || !f)
		return (NULL);
	p = NULL;
	while (lst)
	{
		c = ft_lstnew(f(lst->content));
		if (!c)
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, c);
		lst = lst->next;
	}
	return (p);
}
