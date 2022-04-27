/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:37:46 by izouf             #+#    #+#             */
/*   Updated: 2021/12/29 17:51:57 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_list(t_list *list)
{
	t_command	*command;
	t_command	*delete;

	command = list->head;
	while (command)
	{
		delete = command;
		command = command->next;
		free(delete->name);
		free(delete);
	}
	free(list);
}

void	ft_free_stack(t_stack *stack)
{
	size_t		i;
	t_element	*element;
	t_element	*delete;

	i = 0;
	element = stack->head;
	while (i < stack->size)
	{
		delete = element;
		element = element->next;
		free(delete);
		i++;
	}
	free(stack);
}
