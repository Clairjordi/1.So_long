/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:13:11 by clorcery          #+#    #+#             */
/*   Updated: 2022/06/24 11:38:40 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_window(t_vars *vars)
{
	int	k;

	k = 0;
	while (vars->map_split[k][vars->map_x])
		vars->map_x++;
	while (vars->map_split[k] != NULL)
		k++;
	vars->map_y = k;
	vars->win = mlx_new_window(vars->mlx, (vars->map_x * 32),
			(vars->map_y * 32), "so_long");
	init_img(vars);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
}
