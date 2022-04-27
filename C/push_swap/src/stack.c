/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:40:30 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 13:29:47 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_add_elem(t_stack *stack, t_element *element)
{
	t_element	*tail;

	if (stack && element)
	{
		if (!stack->head)
		{
			stack->head = element;
			stack->head->next = stack->head;
			stack->head->prev = stack->head;
		}
		else
		{
			tail = stack->head->prev;
			tail->next = element;
			element->prev = tail;
			element->next = stack->head;
			stack->head->prev = element;
		}
		stack->size++;
	}
}

void	ft_push(t_element *element, t_stack *stack)
{
	t_element	*tail;

	if (stack && element)
	{
		if (!stack->head)
		{
			stack->head = element;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			tail = stack->head->prev;
			tail->next = element;
			element->prev = tail;
			element->next = stack->head;
			stack->head->prev = element;
			stack->head = element;
		}
		stack->size++;
	}
}

t_element	*ft_pop(t_stack *stack)
{
	t_element	*element;

	element = NULL;
	if (stack && stack->size)
	{
		if (stack->size == 1)
		{
			element = stack->head;
			stack->head = NULL;
			element->prev = NULL;
			element->next = NULL;
		}
		else
		{
			element = stack->head;
			stack->head = stack->head->next;
			element->prev->next = element->next;
			element->next->prev = element->prev;
			element->prev = NULL;
			element->next = NULL;
		}
		stack->size--;
	}
	return (element);
}
