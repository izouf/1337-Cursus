/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:08:36 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 11:25:07 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_finition(t_stack *stack, t_list *list)
{
	t_element	*element;
	size_t		ra_size;
	size_t		rra_size;

	if (stack && stack->head)
	{
		ra_size = 0;
		element = stack->head;
		while (element->i)
		{
			ra_size++;
			element = element->next;
		}
		rra_size = 0;
		element = stack->head;
		while (element->i)
		{
			rra_size++;
			element = element->prev;
		}
		while (stack->head->i && (ra_size < rra_size))
			rx(stack, "ra", list);
		while (stack->head->i && !(ra_size < rra_size))
			rrx(stack, "rra", list);
	}
}

t_list	*ft_solve(t_stack *stack_a)
{
	t_list	*list;
	t_stack	*stack_b;

	list = ft_create_list();
	stack_b = ft_create_stack();
	ft_solve_a(stack_a, stack_b, list);
	ft_solve_b(stack_a, stack_b, list);
	ft_finition(stack_a, list);
	ft_free_stack(stack_b);
	return (list);
}
