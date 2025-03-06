/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:07:14 by oafidi            #+#    #+#             */
/*   Updated: 2025/03/05 01:55:04 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	validate_arguments(int ac, char **av)
{
	size_t	len;

	if (ac != 2)
		return (perror("Error\nUsage: ./so_long <map_path> \n"), 0);
	len = ft_strlen(av[1]);
	if (len < 4 || ft_strcmp(av[1] + len - 4, ".ber"))
		return (perror("Error\nInvalid File\n"), 0);
	return (1);
}

static int	validate_line(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'E')
			game->nbr_exits++;
		else if (line[i] == 'C')
			game->nbr_collectibles++;
		else if (line[i] == 'P')
			game->nbr_players++;
		else if (line[i] != '1' && line[i] != '0' && line[i] != 'N')
			return (perror("Error\nMap Have Invalid Compenents !!\n"), 0);
		i++;
	}
	if (!i)
		return (perror("Error\nMap Have Empty Line !!\n"), 0);
	if (game->map_width == 0 && i)
		return (game->map_width = i, game->map_height++, 1);
	if (game->map_width != i)
		return (perror("Error\nMap Must Be Rectangular !!\n"), 0);
	return (game->map_height++, 1);
}

static char	**ft_read(char *path, t_game *game)
{
	int		fd;
	char	*line;
	char	*str;
	char	**map_grid;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror("Error\nCannot Open File !!\n"), NULL);
	str = NULL;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), perror("Error\nEmpty Map Or Malloc Fail\n"), NULL);
	while (line)
	{
		if (!validate_line(line, game))
			return (close(fd), free(str), free(line), NULL);
		str = ft_strjoin_free(str, line);
		if (!str)
			return (close(fd), NULL);
		line = get_next_line(fd);
	}
	map_grid = ft_split(str, '\n');
	return (close(fd), free(str), map_grid);
}

static int	check_walls(char **map_grid, int height, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map_grid[0][i] != '1' || map_grid[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map_grid[i][0] != '1' || map_grid[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	validate_map(char *path, t_game *game)
{
	game->map_grid = ft_read(path, game);
	if (!game->map_grid)
		return (0);
	if (game->map_height > 44 || game->map_width > 80)
		return (perror("Error\nInvalid Map Size !! \n"), 0);
	if (game->nbr_collectibles < 1)
		return (perror("Error\nMap must have at least one collectible \n"), 0);
	if (game->nbr_exits != 1)
		return (perror("Error\nMap must have one exit !!\n"), 0);
	if (game->nbr_players != 1)
		return (perror("Error\nMap must have one player !!\n"), 0);
	if (!check_walls(game->map_grid, game->map_height, game->map_width))
		return (perror("Error\nMap must be surrounded by walls !!\n"), 0);
	if (!check_path(game))
		return (perror("Error\nInvalid Path !!\n"), 0);
	return (1);
}
