/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bubbles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:12:48 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/04 17:55:36 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_b(t_vars *vars)
{
	int	x;
	int	y;

	vars->nb_b = 0;
	vars->mob = 0;
	y = 0;
	while (vars->map_split[y])
	{
		x = 0;
		while (vars->map_split[y][x])
		{
			if (vars->map_split[y][x] == 'B')
				vars->nb_b++;
			x++;
		}
		y++;
	}
	init_b_bis(vars);
}

void	init_b_bis(t_vars *vars)
{
	if (vars->nb_b > 0)
	{
		vars->bub = malloc(sizeof(t_bubble) * vars->nb_b);
		if (!vars->bub)
			return ;
		vars->mob = 1;
	}
	vars->love_count = 0;
	init_direction(vars);
}

void	init_direction(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->nb_b)
	{
		vars->bub[i].direction = -1;
		vars->bub[i].touch = 0;
		i++;
	}
}

void	where_b(t_vars *vars)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (i < vars->nb_b)
	{
		while (vars->map_split[y] != NULL)
		{
			x = 0;
			while (vars->map_split[y][x])
			{
				if (vars->map_split[y][x] == 'B')
				{
					vars->bub[i].x_b = x;
					vars->bub[i].y_b = y;
					i++;
				}	
				x++;
			}
			y++;
		}
	}
}

int	animation(t_vars *vars)
{
	static int	time;

	if (time == 50000)
	{
		move_bubble(vars);
		time = 0;
	}
	time++;
	return (0);
}
