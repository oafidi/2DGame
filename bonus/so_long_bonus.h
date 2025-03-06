/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:19:19 by oafidi            #+#    #+#             */
/*   Updated: 2025/03/05 03:03:05 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*wall_img;
	void	*exit_img;
	void	*empty_img;
	void	*collectible_img[4];
	void	*ennemie_img[2];
	int		collected;
	int		moves;
	int		exit_x;
	int		exit_y;
	int		player_x;
	int		player_y;
	char	**map_grid;
	int		map_width;
	int		map_height;
	int		nbr_collectibles;
	int		nbr_exits;
	int		nbr_players;
}	t_game;

char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char const *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_free(char *s1, char *s2);
void	free_split(char **p, int n_words);
char	**ft_split(char *s, char c);
int		close_game(t_game *game);
void	free_split(char **p, int n_words);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*get_next_line(int fd);
void	init_map(t_game *game);
int		validate_arguments(int ac, char **av);
int		validate_map(char *path, t_game *game);
void	render_map(t_game *game);
void	init_game(t_game *game);
int		check_path(t_game *game);
char	*ft_itoa(int n);
void	free_memory1(t_game *game);
int		move_ennemie(t_game *game);
void	free_memory(t_game *game);
void	create_map(int ac, char **av, t_game *game);
void	free_images(t_game *game);
int		load_images2(t_game *game, int	*i);
int		handle_keys(int keysym, t_game *game);
void	print_message(t_game *game, int n);

#endif
