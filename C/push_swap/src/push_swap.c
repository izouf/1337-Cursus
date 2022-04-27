/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 07:57:46 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 18:48:20 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_list	*list;

	if (argc >= 2)
	{
		stack = ft_cf_a(argc, argv);
		ft_check_double(stack);
		ft_index_stack(stack);
		ft_markup(stack);
		list = ft_solve(stack);
		ft_free_stack(stack);
		ft_print(list);
		ft_free_list(list);
	}
	return (0);
}
