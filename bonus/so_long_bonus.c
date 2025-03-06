/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:21:35 by oafidi            #+#    #+#             */
/*   Updated: 2025/03/05 02:48:38 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	create_map(argc, argv, &game);
	init_game(&game);
	render_map(&game);
	mlx_hook((&game)->win, 2, 0, handle_keys, &game);
	mlx_hook((&game)->win, 17, 0, close_game, &game);
	mlx_loop_hook((&game)->mlx, move_ennemie, &game);
	mlx_loop((&game)->mlx);
	return (0);
}
