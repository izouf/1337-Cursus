/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 07:51:19 by izouf             #+#    #+#             */
/*   Updated: 2022/01/12 18:08:10 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = malloc(1 * sizeof(t_game));
		if (!game)
			return (ft_putendl_fd("Allocation error game.map !", 2), 0);
		if (!ft_check_map(argv[1], game))
			free(game);
		else
		{
			if (ft_herewego(game))
			{
				ft_hook(game);
				mlx_loop(game->vars->mlx);
			}
		}
	}
	else
		ft_putendl_fd("Args error !", 2);
	return (0);
}
