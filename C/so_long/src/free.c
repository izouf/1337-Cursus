/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:42:39 by izouf             #+#    #+#             */
/*   Updated: 2022/01/12 18:45:31 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_ptr(void **ptr)
{
	if (ptr)
	{
		free (*ptr);
		*ptr = NULL;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_free_game(t_game *game)
{
	ft_mapclear(game->map);
	if (game->vars)
		free(game->vars);
	if (game->player)
		free(game->player);
	if (game->boss)
		free(game->boss);
	if (game->coin)
		free(game->coin);
	if (game->sprite)
		free(game->sprite);
	if (game->exit)
		free(game->exit);
	free_ptr((void **)&game);
}
