/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:42:50 by clorcery          #+#    #+#             */
/*   Updated: 2022/06/17 11:50:26 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_line(char **map_split, t_vars *vars)
{
	vars->map_x = 0;
	vars->map_y = 0;
	while (map_split[vars->map_y][vars->map_x] != '\0')
	{
		vars->map_x++;
	}
	check_size(map_split, vars);
	check_min(map_split, vars);
	check_walls(map_split, vars);
	check_walls_2(map_split, vars);
}

void	check_size(char **map_split, t_vars *vars)
{
	int	i;

	i = 0;
	vars->map_y = 1;
	while (map_split[vars->map_y] != NULL)
	{
		while (map_split[vars->map_y][i] != '\0')
		{
			if (map_split[vars->map_y][i + 1] == '\0' && i + 1 != vars->map_x)
			{
				ft_free_tab_char(map_split);
				ft_error_4(SIZE_ERROR);
			}
			i++;
		}
		i = 0;
		vars->map_y++;
	}
}

void	check_min(char **map_split, t_vars *vars)
{
	if (vars->map_x < 3)
	{
		ft_free_tab_char(map_split);
		ft_error_4(COLUMN_ERROR);
	}
	if (vars->map_y < 3)
	{
		ft_free_tab_char(map_split);
		ft_error_4(LINE_ERROR);
	}
}

void	check_walls(char **map_split, t_vars *vars)
{
	int	x;
	int	y;

	y = 1;
	while (y < vars->map_y)
	{
		x = 0;
		while (map_split[y][x])
		{
			if (map_split[y][0] != '1' || map_split[y][vars->map_x - 1] != '1')
			{
				ft_free_tab_char(map_split);
				ft_error_4(WALLS_ERROR);
			}
			x++;
		}
		y++;
	}
}

void	check_walls_2(char **map_split, t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map_split[y][x])
	{
		if (map_split[y][x] != '1')
		{
			ft_free_tab_char(map_split);
			ft_error_4(WALLS_ERROR);
		}
		x++;
	}
	x = 0;
	while (map_split[vars->map_y - 1][x])
	{
		if (map_split[vars->map_y - 1][x] != '1')
		{
			ft_free_tab_char(map_split);
			ft_error_4(WALLS_ERROR);
		}
		x++;
	}
}
