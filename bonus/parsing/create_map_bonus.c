/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:23:01 by oafidi            #+#    #+#             */
/*   Updated: 2025/03/05 02:13:07 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_memory1(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_images(game);
	free_split(game->map_grid, -1);
	exit(1);
}

void	create_map(int ac, char **av, t_game *game)
{
	if (!validate_arguments(ac, av))
		exit(1);
	init_map(game);
	if (!validate_map(av[1], game))
	{
		free_split(game->map_grid, -1);
		exit(1);
	}
}
