/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:15:19 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/04 17:47:17 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
		ft_printf("You win !\n");
		ft_close(vars);
	}
}

void	check_collision_player(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->nb_b)
	{	
		if (vars->bub[i].x_b == vars->map_x && vars->bub[i].y_b == vars->map_y)
			display_love(vars, i);
		i++;
	}	
}

void	move_player(t_vars *vars, char x_y, int move, char position)
{
	vars->position = position;
	verif_end(vars, x_y, move);
	if (x_y == 'x' && (vars->map_split[vars->map_y][vars->map_x + move] != '1'
		&& vars->map_split[vars->map_y][vars->map_x + move] != 'E'))
	{
		move_sprite_player_x(vars, x_y, move, position);
		vars->map_x += move;
		check_collision_player(vars);
		counter(vars);
	}
	if (x_y == 'y' && (vars->map_split[vars->map_y + move][vars->map_x] != '1'
		&& vars->map_split[vars->map_y + move][vars->map_x] != 'E'))
	{
		move_sprite_player_y(vars, x_y, move);
		vars->map_y += move;
		check_collision_player(vars);
		counter(vars);
	}
	check_collectibles(vars);
	if (vars->nb_c == 0)
		door_open(vars);
}

void	counter(t_vars *vars)
{
	char	*n;

	vars->count++;
	n = ft_itoa(vars->count);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.wall, 2 * 32, 0 * 32);
	mlx_string_put(vars->mlx, vars->win, 75, 18, 0x00FFFFFF, n);
	free(n);
}
