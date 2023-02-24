/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:30:17 by clorcery          #+#    #+#             */
/*   Updated: 2022/06/27 17:33:21 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_sprite_player_x(t_vars *vars, char x_y, int move, char position)
{
	if (x_y == 'x' && position == 'r')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.grass, vars->map_x * 32, vars->map_y * 32);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player_r, (vars->map_x + move) * 32, vars->map_y * 32);
	}
	if (x_y == 'x' && position == 'l')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.grass, vars->map_x * 32, vars->map_y * 32);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player_l, (vars->map_x + move) * 32, vars->map_y * 32);
	}
}

void	move_sprite_player_y(t_vars *vars, char x_y, int move)
{
	if (x_y == 'y')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.grass, vars->map_x * 32, vars->map_y * 32);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player_r, vars->map_x * 32, (vars->map_y + move) * 32);
	}
}
