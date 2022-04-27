/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:28:24 by izouf             #+#    #+#             */
/*   Updated: 2021/12/29 19:01:23 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_needs_pb(t_stack *stack_a)
{
	size_t		i;
	t_element	*element;

	if (stack_a)
	{
		i = 0;
		element = stack_a->head;
		while (i < stack_a->size)
		{
			if (!element->keep)
				return (1);
			i++;
			element = element->next;
		}
	}
	return (0);
}

static int	ft_needs_sa(t_stack *stack_a)
{
	size_t	cp;

	if (stack_a && stack_a->size >= 2)
	{
		sx(stack_a, NULL, NULL);
		cp = ft_u_markup(stack_a, stack_a->markup_head);
		sx(stack_a, NULL, NULL);
		ft_u_markup(stack_a, stack_a->markup_head);
		if (cp > stack_a->pairs)
			return (1);
	}
	return (0);
}

void	ft_solve_a(t_stack *stack_a, t_stack *stack_b, t_list *list)
{
	while (ft_needs_pb(stack_a))
	{
		if (ft_needs_sa(stack_a))
		{
			sx(stack_a, "sa", list);
			stack_a->pairs = ft_u_markup(stack_a, stack_a->markup_head);
		}
		else if (!stack_a->head->keep)
			px(stack_a, stack_b, "pb", list);
		else
			rx(stack_a, "ra", list);
	}
}
