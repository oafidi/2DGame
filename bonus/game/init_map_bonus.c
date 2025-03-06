/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:08:10 by oafidi            #+#    #+#             */
/*   Updated: 2025/03/05 02:12:43 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_map(t_game *game)
{
	int	i;

	i = 0;
	game->map_height = 0;
	game->map_width = 0;
	game->nbr_collectibles = 0;
	game->nbr_exits = 0;
	game->nbr_players = 0;
	game->map_grid = NULL;
	game->exit_x = -1;
	game->exit_y = -1;
	game->player_x = -1;
	game->player_y = -1;
	while (i < 4)
	{
		game->collectible_img[i] = NULL;
		if (i < 2)
			game->ennemie_img[i] = NULL;
		i++;
	}
}

void	print_message(t_game *game, int n)
{
	char	*nbr;
	char	*str;

	str = "move: ";
	nbr = ft_itoa(n);
	str = ft_strjoin(str, nbr);
	free(nbr);
	if (!str)
		return ;
	mlx_string_put(game->mlx, game->win, 12, 5, 0xFFFFFF, str);
	free(str);
}

static int	load_images3(t_game *game, int	*i)
{
	game->ennemie_img[0] = mlx_xpm_file_to_image(game->mlx,
			"bonus/sprites/ennemie0.xpm",
			i, i);
	game->ennemie_img[1] = mlx_xpm_file_to_image(game->mlx,
			"bonus/sprites/ennemie1.xpm",
			i, i);
	if (!game->ennemie_img[0] || !game->ennemie_img[1])
		return (0);
	return (1);
}

int	load_images2(t_game *game, int	*i)
{
	game->collectible_img[0] = mlx_xpm_file_to_image(game->mlx,
			"bonus/sprites/coll0.xpm",
			i, i);
	game->collectible_img[1] = mlx_xpm_file_to_image(game->mlx,
			"bonus/sprites/coll1.xpm",
			i, i);
	game->collectible_img[2] = mlx_xpm_file_to_image(game->mlx,
			"bonus/sprites/coll2.xpm",
			i, i);
	game->collectible_img[3] = mlx_xpm_file_to_image(game->mlx,
			"bonus/sprites/coll3.xpm",
			i, i);
	if (!game->collectible_img[0] || !game->collectible_img[1]
		|| !game->collectible_img[2] || !game->collectible_img[3]
		|| !load_images3(game, i))
		return (0);
	return (1);
}

void	free_memory(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_images(game);
	free_split(game->map_grid, -1);
	exit(0);
}
