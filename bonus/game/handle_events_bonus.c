/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:29:02 by oafidi            #+#    #+#             */
/*   Updated: 2025/03/05 02:38:19 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	update_grid(t_game *game, int new_x, int new_y)
{
	int	i;

	i = 32;
	if (game->map_grid[new_y][new_x] == '0')
		game->map_grid[new_y][new_x] = 'P';
	else if (game->map_grid[new_y][new_x] == 'C')
	{
		game->collected++;
		if (game->collected == game->nbr_collectibles)
		{
			mlx_destroy_image(game->mlx, game->exit_img);
			game->exit_img = mlx_xpm_file_to_image(game->mlx,
					"bonus/sprites/crone.xpm", &i, &i);
			if (!game->exit_img)
			{
				perror("Error\nFailed to load one or more images");
				free_memory1(game);
			}
		}
		game->map_grid[new_y][new_x] = 'P';
	}
	if (game->player_x == game->exit_x && game->player_y == game->exit_y)
		game->map_grid[game->exit_y][game->exit_x] = 'E';
	else
		game->map_grid[game->player_y][game->player_x] = '0';
}

static void	check_exit(t_game *game, int new_x, int new_y)
{
	if (new_x == game->exit_x && new_y == game->exit_y
		&& game->collected == game->nbr_collectibles)
	{
		write(1, "YOU WIN 🏆\n", 13);
		free_memory(game);
	}
}

static int	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map_grid[new_y][new_x] == '1')
		return (0);
	if (game->map_grid[new_y][new_x] == 'N')
	{
		write(1, "You Lose 👾\n​", 14);
		free_memory(game);
	}
	update_grid(game, new_x, new_y);
	check_exit(game, new_x, new_y);
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	render_map(game);
	return (print_message(game, game->moves), 1);
}

int	handle_keys(int keysym, t_game *game)
{
	if (keysym == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_images(game);
		free_split(game->map_grid, -1);
		exit(0);
	}
	else if (keysym == 13 || keysym == 126)
		move_player(game, 0, -1);
	else if (keysym == 1 || keysym == 125)
		move_player(game, 0, 1);
	else if (keysym == 0 || keysym == 123)
		move_player(game, -1, 0);
	else if (keysym == 2 || keysym == 124)
		move_player(game, 1, 0);
	return (0);
}

int	close_game(t_game *game)
{
	free_memory(game);
	return (0);
}
