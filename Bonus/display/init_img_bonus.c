/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:08:45 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/04 16:32:57 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_img(t_vars *vars)
{
	vars->img.grass = mlx_xpm_file_to_image(vars->mlx, GRASS, &vars->width,
			&vars->height);
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx, WALL, &vars->width,
			&vars->height);
	vars->img.item = mlx_xpm_file_to_image(vars->mlx, ITEM, &vars->width,
			&vars->height);
	vars->img.player_r = mlx_xpm_file_to_image(vars->mlx, PLAYER_R,
			&vars->width, &vars->height);
	vars->img.d_close = mlx_xpm_file_to_image(vars->mlx, D_CLOSE,
			&vars->width, &vars->height);
	vars->img.d_open = mlx_xpm_file_to_image(vars->mlx, D_OPEN, &vars->width,
			&vars->height);
	init_other_image(vars);
	put_grass(vars);
	put_walls(vars);
	put_item(vars);
	put_player(vars);
	put_d_close(vars);
	put_bubble(vars);
	let_play(vars);
}

void	init_other_image(t_vars *vars)
{
	vars->img.player_l = mlx_xpm_file_to_image(vars->mlx, PLAYER_L,
			&vars->width, &vars->height);
	vars->img.bubble_l = mlx_xpm_file_to_image(vars->mlx, BUBBLE_L,
			&vars->width, &vars->height);
	vars->img.bubble_heart = mlx_xpm_file_to_image(vars->mlx, BUBBLE_HEART,
			&vars->width, &vars->height);
	vars->img.bubble_r = mlx_xpm_file_to_image(vars->mlx, BUBBLE_R,
			&vars->width, &vars->height);
}

void	let_play(t_vars *vars)
{
	vars->map_y = 0;
	vars->map_x = 0;
	vars->count = 0;
	vars->position = 'n';
	where_p_c(vars);
	init_b(vars);
	where_b(vars);
	mlx_string_put(vars->mlx, vars->win, 5, 18, 0x00FFFFFF, "Compteur : ");
	mlx_string_put(vars->mlx, vars->win, 75, 18, 0x00FFFFFF, "0");
}
