/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:15:19 by clorcery          #+#    #+#             */
/*   Updated: 2022/06/29 14:45:26 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_sprite_player(t_vars *vars, char x_y, int move, char position)
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
	if (x_y == 'y')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.grass, vars->map_x * 32, vars->map_y * 32);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.player_r, vars->map_x * 32, (vars->map_y + move) * 32);
	}
}

void	door_open(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars->map_split[y] != NULL)
	{
		x = 0;
		while (vars->map_split[y][x])
		{
			if (vars->map_split[y][x] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.d_open, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

void	verif_end(t_vars *vars, char x_y, int move)
{
	if (vars->nb_c == 0 && ((x_y == 'x'
				&& vars->map_split[vars->map_y][vars->map_x + move] == 'E')
		|| (x_y == 'y'
			&& vars->map_split[vars->map_y + move][vars->map_x] == 'E')))
	{
		counter(vars);
		ft_printf("You win, congratulations !\n");
		ft_close(vars);
	}
}

void	move_player(t_vars *vars, char x_y, int move, char position)
{
	verif_end(vars, x_y, move);
	if (x_y == 'x' && (vars->map_split[vars->map_y][vars->map_x + move] != '1'
		&& vars->map_split[vars->map_y][vars->map_x + move] != 'E'))
	{
		move_sprite_player(vars, x_y, move, position);
		vars->map_x += move;
		counter(vars);
	}
	if (x_y == 'y' && (vars->map_split[vars->map_y + move][vars->map_x] != '1'
		&& vars->map_split[vars->map_y + move][vars->map_x] != 'E'))
	{
		move_sprite_player(vars, x_y, move, position);
		vars->map_y += move;
		counter(vars);
	}
	check_collectibles(vars);
	if (vars->nb_c == 0)
		door_open(vars);
}

void	counter(t_vars *vars)
{
	vars->count++;
	ft_printf("%d\n", vars->count);
}
