/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:09:31 by clorcery          #+#    #+#             */
/*   Updated: 2022/06/24 12:38:26 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_grass(t_vars *vars)
{
	vars->map_y = 0;
	while (vars->map_split[vars->map_y] != NULL)
	{
		vars->map_x = 0;
		while (vars->map_split[vars->map_y][vars->map_x])
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.grass,
				vars->map_x * 32, vars->map_y * 32);
			vars->map_x++;
		}
		vars->map_y++;
	}
}

void	put_walls(t_vars *vars)
{
	vars->map_y = 0;
	while (vars->map_split[vars->map_y] != NULL)
	{
		vars->map_x = 0;
		while (vars->map_split[vars->map_y][vars->map_x])
		{
			if (vars->map_split[vars->map_y][vars->map_x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.wall, vars->map_x * 32, vars->map_y * 32);
			vars->map_x++;
		}
		vars->map_y++;
	}
}

void	put_item(t_vars *vars)
{
	vars->map_y = 0;
	while (vars->map_split[vars->map_y] != NULL)
	{
		vars->map_x = 0;
		while (vars->map_split[vars->map_y][vars->map_x])
		{
			if (vars->map_split[vars->map_y][vars->map_x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.item, vars->map_x * 32, vars->map_y * 32);
			vars->map_x++;
		}
		vars->map_y++;
	}
}

void	put_player(t_vars *vars)
{
	vars->map_y = 0;
	while (vars->map_split[vars->map_y] != NULL)
	{
		vars->map_x = 0;
		while (vars->map_split[vars->map_y][vars->map_x])
		{
			if (vars->map_split[vars->map_y][vars->map_x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.player_r, vars->map_x * 32, vars->map_y * 32);
			vars->map_x++;
		}
		vars->map_y++;
	}
}
