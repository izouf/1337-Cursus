/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:32:51 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 17:30:07 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_add_command(t_list *list, t_command *command)
{
	t_command	*last;

	if (list && command)
	{
		if (!list->head)
			list->head = command;
		else
		{
			last = list->head;
			while (last->next)
				last = last->next;
			last->next = command;
		}
		list->size++;
	}
}

void	ft_print(t_list *list)
{
	t_command	*command;

	command = list->head;
	while (command)
	{
		ft_putendl_fd(command->name, 1);
		command = command->next;
	}
}

void	ft_exec_command(t_stack *stack_a, t_stack *stack_b, char *command)
{
	if (!ft_strcmp(command, "sa\n"))
		sx(stack_a, NULL, NULL);
	else if (!ft_strcmp(command, "sb\n"))
		sx(stack_b, NULL, NULL);
	else if (!ft_strcmp(command, "ss\n"))
		ss(stack_a, stack_b, NULL, NULL);
	else if (!ft_strcmp(command, "pa\n"))
		px (stack_b, stack_a, NULL, NULL);
	else if (!ft_strcmp(command, "pb\n"))
		px (stack_a, stack_b, NULL, NULL);
	else if (!ft_strcmp(command, "ra\n"))
		rx(stack_a, NULL, NULL);
	else if (!ft_strcmp(command, "rb\n"))
		rx(stack_b, NULL, NULL);
	else if (!ft_strcmp(command, "rr\n"))
		rr(stack_a, stack_b, NULL, NULL);
	else if (!ft_strcmp(command, "rra\n"))
		rrx(stack_a, NULL, NULL);
	else if (!ft_strcmp(command, "rrb\n"))
		rrx(stack_b, NULL, NULL);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(stack_a, stack_b, NULL, NULL);
	else
		ft_error();
}
