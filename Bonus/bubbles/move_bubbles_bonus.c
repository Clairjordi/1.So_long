/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bubbles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:56:56 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/04 16:36:38 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_bubble_right(t_vars *vars, int i)
{
	int	move;

	move = 1;
	if (vars->map_split[vars->bub[i].y_b][vars->bub[i].x_b + 1] != '1'
			&& vars->map_split[vars->bub[i].y_b]
			[vars->bub[i].x_b + 1] != 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.grass,
			vars->bub[i].x_b * 32, vars->bub[i].y_b * 32);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.bubble_r,
			(vars->bub[i].x_b + 1) * 32, vars->bub[i].y_b * 32);
		vars->bub[i].x_b += move;
	}
}

void	move_bubble_left(t_vars *vars, int i)
{
	int	move;

	move = 1;
	if (vars->map_split[vars->bub[i].y_b][vars->bub[i].x_b - 1] != '1'
			&& vars->map_split[vars->bub[i].y_b]
			[vars->bub[i].x_b - 1] != 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.grass,
			vars->bub[i].x_b * 32, vars->bub[i].y_b * 32);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.bubble_l,
			(vars->bub[i].x_b - 1) * 32, vars->bub[i].y_b * 32);
		vars->bub[i].x_b -= move;
	}
}

void	direction_bubble(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->nb_b)
	{
		if (vars->bub[i].direction == -1
			&& (vars->map_split[vars->bub[i].y_b][vars->bub[i].x_b - 1] == '1'
			|| vars->map_split[vars->bub[i].y_b][vars->bub[i].x_b - 1] == 'E'
			|| vars->map_split[vars->bub[i].y_b][vars->bub[i].x_b - 1] == 'C'))
			vars->bub[i].direction = 1;
		if (vars->bub[i].direction == 1
			&& (vars->map_split[vars->bub[i].y_b][vars->bub[i].x_b + 1] == '1'
			|| vars->map_split[vars->bub[i].y_b][vars->bub[i].x_b + 1] == 'E'
			|| vars->map_split[vars->bub[i].y_b][vars->bub[i].x_b + 1] == 'C'))
			vars->bub[i].direction = -1;
		i++;
	}
}

void	move_bubble(t_vars *vars)
{
	int	i;

	i = 0;
	direction_bubble(vars);
	while (i < vars->nb_b)
	{
		if (vars->bub[i].direction == 1)
			move_bubble_right(vars, i);
		else if (vars->bub[i].direction == -1)
			move_bubble_left(vars, i);
		check_collision_bubble(vars, i);
		i++;
	}
	verif_love_counter(vars);
}
