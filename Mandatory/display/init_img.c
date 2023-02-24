/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:08:45 by clorcery          #+#    #+#             */
/*   Updated: 2022/06/28 13:08:16 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	vars->img.player_l = mlx_xpm_file_to_image(vars->mlx, PLAYER_L,
			&vars->width, &vars->height);
	vars->img.d_close = mlx_xpm_file_to_image(vars->mlx, D_CLOSE, &vars->width,
			&vars->height);
	vars->img.d_open = mlx_xpm_file_to_image(vars->mlx, D_OPEN, &vars->width,
			&vars->height);
	put_grass(vars);
	put_walls(vars);
	put_item(vars);
	put_player(vars);
	put_d_close(vars);
	vars->map_y = 0;
	vars->map_x = 0;
	vars->count = 0;
	where_p_c(vars);
}
