/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <izouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:08:37 by izouf             #+#    #+#             */
/*   Updated: 2022/04/26 15:13:41 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(void)
{
	exit(1);
	return (0);
}

void	ft_free(t_cub *parsing, t_game *game)
{
	int	i;

	free(parsing->info.n);
	free(parsing->info.s);
	free(parsing->info.e);
	free(parsing->info.w);
	i = -1;
	while (parsing->map[++i])
		free(parsing->map[i]);
	free (parsing->map);
	i = -1;
	while (++i < S_H)
		free(game->ray->buffer[i]);
	free(game->ray->buffer);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_cub	parsing;

	if (ac != 2)
		return (printf("wrong arg"), 0);
	big_parss(ac, av, &parsing, 'm');
	ft_herewego(&game, parsing, 0);
	ft_free(&parsing, &game);
	return (0);
}
