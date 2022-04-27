/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:40:07 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 18:41:11 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_double(t_stack *stack)
{
	size_t		i;
	t_element	*eli;
	t_element	*elj;

	i = 0;
	eli = stack->head;
	while (i < stack->size)
	{
		elj = eli->next;
		while (elj != eli)
		{
			if (eli->n == elj->n)
			{
				ft_free_stack(stack);
				ft_error();
			}
			elj = elj->next;
		}
		i++;
		eli = eli->next;
	}
}

static char	**ft_check_arg(int argc, char **argv)
{
	int		i;
	char	**stack;
	char	*join;

	join = ft_strjoin(argc, argv, " ");
	stack = ft_split(join, ' ');
	free (join);
	i = 0;
	while (stack[++i])
	{
		if (!ft_isint(stack[i]))
			ft_error();
	}
	return (stack);
}

t_stack	*ft_cf_a(int argc, char **argv)
{
	size_t	i;
	t_stack	*stack;
	char	**tab;

	i = 0;
	stack = ft_create_stack();
	tab = ft_check_arg(argc, argv);
	while (tab[++i])
		ft_add_elem(stack, ft_create_element(ft_atoi(tab[i])));
	free_tab(tab);
	if (!stack->size)
		exit(1);
	return (stack);
}
