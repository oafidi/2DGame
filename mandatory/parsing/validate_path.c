/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:18:03 by oafidi            #+#    #+#             */
/*   Updated: 2025/03/02 03:10:27 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**create_temp_grid(char **map_grid, int height)
{
	char	**temp_grid;
	int		i;

	temp_grid = malloc(sizeof(char *) * (height + 1));
	if (!temp_grid)
		return (NULL);
	i = 0;
	while (i < height)
	{
		temp_grid[i] = ft_strdup(map_grid[i]);
		if (!temp_grid[i])
			return (free_split(temp_grid, i), NULL);
		i++;
	}
	temp_grid[i] = NULL;
	return (temp_grid);
}

static void	player_exit_positions(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_grid[i])
	{
		j = 0;
		while (game->map_grid[i][j])
		{
			if (game->map_grid[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
			}
			if (game->map_grid[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			if (game->exit_x != -1 && game->player_x != -1)
				return ;
			j++;
		}
		i++;
	}
}

static void	flood_fill(char **temp_grid, int p_x, int p_y, t_game *game)
{
	if (p_x < 0 || p_y < 0 || p_x >= game->map_width || p_y >= game->map_height
		|| temp_grid[p_y][p_x] == '1')
		return ;
	temp_grid[p_y][p_x] = '1';
	flood_fill(temp_grid, p_x + 1, p_y, game);
	flood_fill(temp_grid, p_x - 1, p_y, game);
	flood_fill(temp_grid, p_x, p_y + 1, game);
	flood_fill(temp_grid, p_x, p_y - 1, game);
}

static int	check_reach(char **temp_grid, char **map_grid, t_game *game)
{
	int	i;
	int	j;
	int	collected;
	int	exit;

	i = 0;
	collected = 0;
	exit = 0;
	while (map_grid[i])
	{
		j = 0;
		while (map_grid[i][j])
		{
			if (map_grid[i][j] == 'C' && temp_grid[i][j] == '1')
				collected++;
			if (map_grid[i][j] == 'E' && temp_grid[i][j] == '1')
				exit++;
			j++;
		}
		i++;
	}
	return (exit && (collected == game->nbr_collectibles));
}

int	check_path(t_game *game)
{
	char	**temp_grid;
	int		result;

	temp_grid = create_temp_grid(game->map_grid, game->map_height);
	if (!temp_grid)
	{
		free_split(game->map_grid, -1);
		exit(1);
	}
	player_exit_positions(game);
	flood_fill(temp_grid, game->player_x, game->player_y, game);
	result = check_reach(temp_grid, game->map_grid, game);
	free_split(temp_grid, -1);
	return (result);
}
