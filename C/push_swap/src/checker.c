/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:11:38 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 17:48:56 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_sorted(t_stack *stack)
{
	size_t		i;
	t_element	*element;
	int			prev_n;

	i = 1;
	element = stack->head->next;
	prev_n = stack->head->n;
	while (i < stack->size)
	{
		if (element->n < prev_n)
			return (0);
		prev_n = element->n;
		i++;
		element = element->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (argc >= 2)
	{
		stack_a = ft_cf_a(argc, argv);
		ft_check_double(stack_a);
		stack_b = ft_create_stack();
		line = get_next_line(0);
		while (line && line[0] != '\n')
		{
			ft_exec_command(stack_a, stack_b, line);
			free(line);
			line = get_next_line(0);
		}
		if (stack_b->head == NULL && ft_sorted(stack_a))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
	}
	return (0);
}
