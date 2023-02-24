/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:23:55 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/04 18:37:22 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	verif_love_counter(t_vars *vars)
{
	if (vars->love_count >= 3)
	{
		ft_printf("Your love level is full XD !\n");
		ft_close(vars);
	}
}

void	display_love(t_vars *vars, int i)
{
	mlx_string_put(vars->mlx, vars->win, 97, 18, 0x00FFFFFF, "Love :");
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.bubble_heart, 5 * 32, 0 * 32);
	love_counter(vars);
	vars->bub[i].touch = 1;
}

void	check_collision_bubble(t_vars *vars, int i)
{
	if (vars->position == 'n')
		vars->position = 'r';
	if (vars->bub[i].touch == 1)
	{
		if (vars->position == 'r')
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img.player_r, vars->map_x * 32, vars->map_y * 32);
		}
		else if (vars->position == 'l')
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img.player_l, vars->map_x * 32, vars->map_y * 32);
		vars->bub[i].touch = 0;
	}
	if (vars->bub[i].x_b == vars->map_x && vars->bub[i].y_b == vars->map_y)
		display_love(vars, i);
}

void	love_counter(t_vars *vars)
{
	char	*n;

	vars->love_count++;
	n = ft_itoa(vars->love_count);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.wall, 4 * 32, 0 * 32);
	mlx_string_put(vars->mlx, vars->win, 137, 18, 0x00FFFFFF, n);
	free(n);
}
