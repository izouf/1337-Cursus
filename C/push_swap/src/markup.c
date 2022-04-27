/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:34:04 by izouf             #+#    #+#             */
/*   Updated: 2021/12/29 16:21:53 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_u_markup(t_stack *stack, t_element *markup_head)
{
	ssize_t		i;
	size_t		p;
	t_element	*element;

	p = 0;
	if (stack && markup_head)
	{
		i = markup_head->i;
		markup_head->keep = 1;
		element = markup_head->next;
		while (element != markup_head)
		{
			if (element->i > i)
			{
				p++;
				i = element->i;
				element->keep = 1;
			}
			else
				element->keep = 0;
			element = element->next;
		}
	}
	return (p);
}

void	ft_markup(t_stack *stack)
{
	size_t		i;
	size_t		cp;
	t_element	*tmp;

	if (stack)
	{
		i = 0;
		tmp = stack->head;
		while (i < stack->size)
		{
			cp = ft_u_markup(stack, tmp);
			if (cp > stack->pairs)
			{
				stack->markup_head = tmp;
				stack->pairs = cp;
			}
			else if (cp == stack->pairs && (!stack->markup_head
					|| tmp->n < stack->markup_head->n))
				stack->markup_head = tmp;
			i++;
			tmp = tmp->next;
		}
	}
	ft_u_markup(stack, stack->markup_head);
}
