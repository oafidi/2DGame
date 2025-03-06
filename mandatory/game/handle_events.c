/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:29:02 by oafidi            #+#    #+#             */
/*   Updated: 2025/03/02 03:27:59 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_grid(t_game *game, int new_x, int new_y)
{
	if (game->map_grid[new_y][new_x] == '0')
		game->map_grid[new_y][new_x] = 'P';
	else if (game->map_grid[new_y][new_x] == 'C')
	{
		game->collected++;
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
		write(1, "YOU WIN 🏆\n", 14);
		mlx_destroy_window(game->mlx, game->win);
		free_images(game);
		free_split(game->map_grid, -1);
		exit(0);
	}
}

static void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map_grid[new_y][new_x] == '1')
		return ;
	update_grid(game, new_x, new_y);
	check_exit(game, new_x, new_y);
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
	render_map(game);
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
	free_images(game);
	free_split(game->map_grid, -1);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}
