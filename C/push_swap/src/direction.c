/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:31:23 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 13:26:16 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_element	*ft_find_ela(t_stack *stack_a, int index)
{
	t_element	*element;

	element = stack_a->markup_head;
	if (index < element->i)
	{
		while (index < element->prev->i && element->i > element->prev->i)
			element = element->prev;
	}
	else
	{
		while (index > element->i && element->i < element->next->i)
			element = element->next;
		if (index > element->i && element-> i > element->next->i)
			element = element->next;
	}
	return (element);
}

static void	ft_estimate(t_stack *stack, int index,
		size_t *rx_size, size_t *rrx_size)
{
	t_element	*element;

	if (stack && stack->head)
	{
		element = stack->head;
		while (element->i != index)
		{
			(*rx_size)++;
			element = element->next;
		}
		element = stack->head;
		while (element->i != index)
		{
			(*rrx_size)++;
			element = element->prev;
		}
	}
}

static void	ft_set_direction(size_t size, t_shift new, t_shift *shift)
{
	if (!shift->is_set || size < shift->size)
	{
		shift->ela = new.ela;
		shift->elb = new.elb;
		shift->dira = new.dira;
		shift->dirb = new.dirb;
		shift->size = size;
		shift->is_set = 1;
	}
}

static void	ft_u_direction(t_stack *stack_a, t_stack *stack_b,
		t_element *element_b, t_shift *shift)
{
	t_shift	new;
	size_t	ra_size;
	size_t	rra_size;
	size_t	rb_size;
	size_t	rrb_size;

	ra_size = 0;
	rra_size = 0;
	rb_size = 0;
	rrb_size = 0;
	new.ela = ft_find_ela(stack_a, element_b->i);
	new.elb = element_b;
	ft_estimate(stack_a, new.ela->i, &ra_size, &rra_size);
	ft_estimate(stack_b, element_b->i, &rb_size, &rrb_size);
	new.dira = 0;
	new.dirb = 0;
	ft_set_direction(ft_max(ra_size, rb_size), new, shift);
	new.dira = 1;
	ft_set_direction(rra_size + rb_size, new, shift);
	new.dirb = 1;
	ft_set_direction(ft_max(rra_size, rrb_size), new, shift);
	new.dira = 0;
	ft_set_direction(ra_size + rrb_size, new, shift);
}

void	ft_direction(t_stack *stack_a, t_stack *stack_b, t_shift *shift)
{
	size_t		i;
	t_element	*element;

	if (stack_b)
	{
		i = 0;
		element = stack_b->head;
		while (i < stack_b->size)
		{
			ft_u_direction(stack_a, stack_b, element, shift);
			i++;
			element = element->next;
		}
	}
}
