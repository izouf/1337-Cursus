/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:54:12 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 13:31:44 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap(t_element *first, t_element *sec, t_stack *stack)
{
	t_element	*prev;
	t_element	*next;

	prev = first->prev;
	next = sec->next;
	prev->next = sec;
	sec->prev = prev;
	first->next = next;
	next->prev = first;
	sec->next = first;
	first->prev = sec;
	stack->head = sec;
}

void	px(t_stack *from, t_stack *to, char *name, t_list *list)
{
	ft_push(ft_pop(from), to);
	if (name && !list)
		ft_putendl_fd(name, 1);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}

void	sx(t_stack *stack, char *name, t_list *list)
{
	if (stack && stack->head && stack->size >= 2)
		ft_swap(stack->head, stack->head->next, stack);
	if (name && !list)
		ft_putendl_fd(name, 1);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}

void	ss(t_stack *a, t_stack *b, char *name, t_list *list)
{
	sx(a, NULL, NULL);
	sx(b, NULL, NULL);
	if (name && !list)
		ft_putendl_fd(name, 1);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}
