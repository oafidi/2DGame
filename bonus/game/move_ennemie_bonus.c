/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemie_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:46:09 by oafidi            #+#    #+#             */
/*   Updated: 2025/03/05 02:38:35 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	swap_ennemie(t_game *game, int direction)
{
	static int	flag;
	void		*temp;

	if (flag != direction)
	{
		temp = game->ennemie_img[0];
		game->ennemie_img[0] = game->ennemie_img[1];
		game->ennemie_img[1] = temp;
		flag = direction;
	}
	return ;
}

static int	chose_move(t_game *game, int x, int y)
{
	char	**map;

	map = game->map_grid;
	if (y > game->player_y && (map[y - 1][x] == '0' || map[y - 1][x] == 'P'))
		return (1);
	if (y < game->player_y && (map[y + 1][x] == '0' || map[y + 1][x] == 'P'))
		return (2);
	if (x > game->player_x && (map[y][x - 1] == '0' || map[y][x - 1] == 'P'))
		return (3);
	if (x < game->player_x && (map[y][x + 1] == '0' || map[y][x + 1] == 'P'))
		return (4);
	return (0);
}

static void	do_move2(t_game *game, int *x, int *y, int move)
{
	if (move == 3)
	{
		if (*y == game->player_y && *x - 1 == game->player_x)
		{
			write(1, "You Lose 👾\n​", 14);
			free_memory(game);
		}
		game->map_grid[*y][*x] = '0';
		game->map_grid[*y][*x - 1] = 'N';
		swap_ennemie(game, 1);
	}
	if (move == 4)
	{
		if (*y == game->player_y && *x + 1 == game->player_x)
		{
			write(1, "You Lose 👾\n​", 14);
			free_memory(game);
		}
		game->map_grid[*y][*x] = '0';
		game->map_grid[*y][*x + 1] = 'N';
		*x = *x + 1;
		swap_ennemie(game, 0);
	}
}

static void	do_move(t_game *game, int *x, int *y)
{
	int	move;

	move = chose_move(game, *x, *y);
	if (move == 1)
	{
		if (*y - 1 == game->player_y && *x == game->player_x)
		{
			write(1, "You Lose 👾\n​", 14);
			free_memory(game);
		}
		game->map_grid[*y][*x] = '0';
		game->map_grid[*y - 1][*x] = 'N';
	}
	else if (move == 2)
	{
		if (*y + 1 == game->player_y && *x == game->player_x)
		{
			write(1, "You Lose 👾\n​", 14);
			free_memory(game);
		}
		game->map_grid[*y][*x] = '0';
		game->map_grid[*y + 1][*x] = 'N';
		*y = *y + 1;
	}
	do_move2(game, x, y, move);
}

int	move_ennemie(t_game *game)
{
	static int	frame_count;
	int			i;
	int			j;

	i = 0;
	if (frame_count == 2000)
	{
		while (game->map_grid[i])
		{
			j = 0;
			while (game->map_grid[i][j])
			{
				if (game->map_grid[i][j] == 'N')
				{
					do_move(game, &j, &i);
					render_map(game);
					print_message(game, game->moves);
				}
				j++;
			}
			i++;
		}
		frame_count = 0;
	}
	return (frame_count++, 0);
}
