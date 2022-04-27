/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 08:10:24 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 13:31:12 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_element	*ft_min_element(t_stack *stack)
{
	size_t		i;
	int			no_min;
	t_element	*element;
	t_element	*min;

	min = NULL;
	if (stack)
	{
		i = 0;
		no_min = 1;
		element = stack->head;
		while (i < stack->size)
		{
			if (element->i == -1 && (no_min || element->n < min->n))
			{
				no_min = 0;
				min = element;
			}
			i++;
			element = element->next;
		}
	}
	return (min);
}

void	ft_index_stack(t_stack *stack)
{
	size_t		i;
	t_element	*element;

	i = 0;
	while (1)
	{
		element = ft_min_element(stack);
		if (!element)
			break ;
		element->i = i++;
	}
}
