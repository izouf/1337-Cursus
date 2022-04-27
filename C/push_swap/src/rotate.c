/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 09:01:18 by izouf             #+#    #+#             */
/*   Updated: 2021/12/28 09:11:34 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rx(t_stack *stack, char *name, t_list *list)
{
	if (stack && stack->head)
		stack->head = stack->head->next;
	if (name && !list)
		ft_putendl_fd(name, 1);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}

void	rr(t_stack *a, t_stack *b, char *name, t_list *list)
{
	rx(a, NULL, NULL);
	rx(b, NULL, NULL);
	if (name && !list)
		ft_putendl_fd(name, 1);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}

void	rrx(t_stack *stack, char *name, t_list *list)
{
	if (stack && stack->head)
		stack->head = stack->head->prev;
	if (name && !list)
		ft_putendl_fd(name, 1);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}

void	rrr(t_stack *a, t_stack *b, char *name, t_list *list)
{
	rrx(a, NULL, NULL);
	rrx(b, NULL, NULL);
	if (name && !list)
		ft_putendl_fd(name, 1);
	if (name && list)
		ft_add_command(list, ft_create_command(name));
}
