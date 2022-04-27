/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:14:05 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 13:29:22 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_rotate_b(t_stack *stack_a, t_stack *stack_b,
		t_shift *shift, t_list *list)
{
	while (shift->ela != stack_a->head || shift->elb != stack_b->head)
	{
		if (shift->dira == shift->dirb && shift->ela != stack_a->head
			&& shift->elb != stack_b->head)
		{
			if (!shift->dira)
				rr(stack_a, stack_b, "rr", list);
			else
				rrr(stack_a, stack_b, "rrr", list);
		}
		else if (shift->ela != stack_a->head)
		{
			if (!shift->dira)
				rx(stack_a, "ra", list);
			else
				rrx(stack_a, "rra", list);
		}
		else if (shift->elb != stack_b->head)
		{
			if (!shift->dirb)
				rx(stack_b, "rb", list);
			else
				rrx(stack_b, "rrb", list);
		}
	}
}

void	ft_solve_b(t_stack *stack_a, t_stack *stack_b, t_list *list)
{
	t_shift	*shift;

	shift = ft_create_shift();
	while (stack_b->size)
	{
		shift->is_set = 0;
		ft_direction(stack_a, stack_b, shift);
		ft_rotate_b(stack_a, stack_b, shift, list);
		px(stack_b, stack_a, "pa", list);
	}
	free(shift);
}
