/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:26:02 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/04 17:33:36 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/all_h.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//~~~~~~~~ERROR~~~~~~~~//
# define ARG_ERROR 1
# define EXT_ERROR 2
# define MAP_VOID 3
# define MAP_LETTER_ERROR 4
# define MAP_SIZE_ERROR 5
# define MAP_NOT_CLOSED 6
# define FD_ERROR 7
# define RD_ERROR 8
# define LETTER_E_P_ERROR 9
# define LETTER_C_ERROR 10
# define MAP_ERROR 11
# define COLUMN_ERROR 12
# define LINE_ERROR 13
# define WALLS_ERROR 14
# define SIZE_ERROR 15

//~~~~~~~SPRITES~~~~~~//
# define WALL "./sprites/bush.xpm"
# define GRASS "./sprites/grass3.xpm"
# define ITEM "./sprites/item1.xpm"
# define PLAYER_R "./sprites/player_right.xpm"
# define PLAYER_L "./sprites/player_left.xpm"
# define D_CLOSE "./sprites/door_close1.xpm"
# define D_OPEN "./sprites/door_open1.xpm"
# define BUBBLE_L "./sprites/bubble_left.xpm"
# define BUBBLE_HEART "./sprites/bubble_heart.xpm"
# define BUBBLE_R "./sprites/bubble_right.xpm"

typedef struct s_bubble
{
	int		x_b;
	int		y_b;
	int		direction;
	int		touch;
}	t_bubble;

typedef struct s_imgs
{
	void	*wall;
	void	*grass;
	void	*item;
	void	*player_r;
	void	*player_l;
	void	*bubble_l;
	void	*bubble_heart;
	void	*bubble_r;
	void	*d_close;
	void	*d_open;
}	t_imgs;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		**map_split;
	int			map_x;
	int			map_y;
	char		position;
	int			nb_c;
	int			count;
	int			width;
	int			height;
	int			nb_b;
	int			love_count;
	int			mob;
	int			mob_heart;
	t_imgs		img;
	t_bubble	*bub;
}	t_vars;

//CHERCK_ARG
int		check_file(char *s);
char	*recup_map(char *file_name);
void	ft_error_1(int n, char *s);
void	ft_error_2(int n, char *s);
void	ft_error_3(int n, char *s, t_vars *vars);
void	ft_error_4(int n);
void	check_letter_map(char *file_name, t_vars *vars);
void	check_letter_e_p(char *filename, t_vars *vars);
void	check_extension(char *file);
void	check_argc(int ac, char *file_name, t_vars *vars);
void	check_letter_c(char *filename, t_vars *vars);
void	check_bsn(char *filename);
char	**recup_map_split(char *file, t_vars *vars);
void	check_line(char **map_split, t_vars *vars);
void	check_size(char **map_split, t_vars *vars);
void	check_min(char **map_split, t_vars *vars);
void	check_walls(char **map_split, t_vars *vars);
void	check_walls_2(char **map_split, t_vars *vars);

//WINDOW
void	open_window(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		ft_close(t_vars *vars);
void	close_window(t_vars *vars);
void	destroy_image(t_vars *vars);

//DISPLAY
void	init_img(t_vars *vars);
void	put_grass(t_vars *vars);
void	put_walls(t_vars *vars);
void	put_item(t_vars *vars);
void	put_player(t_vars *vars);
void	put_d_close(t_vars *vars);
void	put_d_open(t_vars *vars);
void	put_bubble(t_vars *vars);
void	put_bubble_heart(t_vars *vars);
void	let_play(t_vars *vars);
void	init_other_image(t_vars *vars);

//PLAYER
void	move_player(t_vars *vars, char x_y, int move, char position);
void	move_sprite_player_x(t_vars *vars, char x_y, int move, char position);
void	move_sprite_player_y(t_vars *vars, char x_y, int move);
void	where_p_c(t_vars *vars);
void	check_collectibles(t_vars *vars);
void	counter(t_vars *vars);
void	verif_end(t_vars *vars, char x_y, int move);
void	check_collision_player(t_vars *vars);

//ANIMATION
int		animation(t_vars *vars);
void	move_bubble(t_vars *vars);
void	where_b(t_vars *vars);
void	init_b_bis(t_vars *vars);
void	init_b(t_vars *vars);
void	direction_bubble(t_vars *vars);
void	move_bubble_left(t_vars *vars, int i);
void	move_bubble_right(t_vars *vars, int i);
void	init_direction(t_vars *vars);
void	check_collision_bubble(t_vars *vars, int i);
void	love_counter(t_vars *vars);
void	verif_love_counter(t_vars *vars);
void	display_love(t_vars *vars, int i);

#endif
