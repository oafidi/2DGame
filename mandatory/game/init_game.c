/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:23:18 by oafidi            #+#    #+#             */
/*   Updated: 2025/03/02 08:47:40 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_images(t_game *game)
{
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->empty_img)
		mlx_destroy_image(game->mlx, game->empty_img);
	if (game->collectible_img[0])
		mlx_destroy_image(game->mlx, game->collectible_img[0]);
	if (game->collectible_img[1])
		mlx_destroy_image(game->mlx, game->collectible_img[1]);
	if (game->collectible_img[2])
		mlx_destroy_image(game->mlx, game->collectible_img[2]);
	if (game->collectible_img[3])
		mlx_destroy_image(game->mlx, game->collectible_img[3]);
}

static void	load_images(t_game *game, int	*i)
{
	game->empty_img = mlx_xpm_file_to_image(game->mlx,
			"mandatory/sprites/empty.xpm",
			i, i);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"mandatory/sprites/tresor.xpm",
			i, i);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"mandatory/sprites/player.xpm",
			i, i);
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"mandatory/sprites/wall.xpm",
			i, i);
	if (!game->empty_img || !game->exit_img || !game->player_img
		|| !game->wall_img || !load_images2(game, i))
	{
		free_images(game);
		perror("Error\nFailed to load one or more images");
		mlx_destroy_window(game->mlx, game->win);
		free_split(game->map_grid, -1);
		exit(1);
	}
}

void	init_game(t_game *game)
{
	int	i;

	i = 32;
	game->collected = 0;
	game->moves = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error\nFailed to initialize mlx\n");
		free_split(game->map_grid, -1);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->map_width * 32,
			game->map_height * 32, "Ghost");
	if (!game->win)
	{
		perror("Error\nFailed to create win\n");
		free_split(game->map_grid, -1);
		exit(1);
	}
	load_images(game, &i);
}

static void	put_tile(t_game *game, char tile, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->empty_img, x * 32, y * 32);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_img, x * 32, y * 32);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_img, x * 32, y * 32);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible_img[x % 4], x * 32, y * 32);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_img, x * 32, y * 32);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_grid[i])
	{
		j = 0;
		while (game->map_grid[i][j])
		{
			put_tile(game, game->map_grid[i][j], j, i);
			if (j == game->player_x && i == game->player_y)
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->player_img, j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
}
