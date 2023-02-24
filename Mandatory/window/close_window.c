/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:47:16 by clorcery          #+#    #+#             */
/*   Updated: 2022/06/27 18:15:41 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_image(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.grass);
	mlx_destroy_image(vars->mlx, vars->img.wall);
	mlx_destroy_image(vars->mlx, vars->img.item);
	mlx_destroy_image(vars->mlx, vars->img.player_r);
	mlx_destroy_image(vars->mlx, vars->img.player_l);
	mlx_destroy_image(vars->mlx, vars->img.d_close);
	mlx_destroy_image(vars->mlx, vars->img.d_open);
}

int	ft_close(t_vars *vars)
{
	ft_free_tab_char(vars->map_split);
	mlx_clear_window(vars->mlx, vars->win);
	destroy_image(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(1);
	return (0);
}

void	close_window(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, ft_close, vars);
}
