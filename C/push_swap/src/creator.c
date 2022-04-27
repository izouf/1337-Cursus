/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:31:37 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 13:23:22 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_create_stack(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		ft_error();
	stack->head = NULL;
	stack->size = 0;
	stack->pairs = 0;
	stack->markup_head = NULL;
	return (stack);
}

t_element	*ft_create_element(int n)
{
	t_element	*new;

	new = ft_calloc(1, sizeof(t_element));
	if (!new)
		ft_error();
	new->n = n;
	new->i = -1;
	new->keep = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_list	*ft_create_list(void)
{
	t_list	*list;

	list = ft_calloc(1, sizeof(t_list));
	if (!list)
		ft_error();
	list->size = 0;
	list->head = NULL;
	return (list);
}

t_command	*ft_create_command(char *name)
{
	t_command	*command;

	command = ft_calloc(1, sizeof(t_command));
	if (!command)
		ft_error();
	command->name = ft_strdup(name);
	if (!command->name)
		ft_error();
	command->next = NULL;
	return (command);
}

t_shift	*ft_create_shift(void)
{
	t_shift	*shift;

	shift = ft_calloc(1, sizeof(t_shift));
	if (!shift)
		ft_error();
	shift->ela = NULL;
	shift->elb = NULL;
	shift->dira = 0;
	shift->dirb = 0;
	shift->size = 0;
	shift->is_set = 0;
	return (shift);
}
