/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:57:46 by clorcery          #+#    #+#             */
/*   Updated: 2022/06/16 19:58:43 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	where_p_c(t_vars *vars)
{
	int	k;
	int	j;

	k = 0;
	vars->nb_c = 0;
	if (vars->map_y == 0 && vars->map_x == 0)
	{
		while (vars->map_split[k] != NULL)
		{
			j = 0;
			while (vars->map_split[k][j])
			{
				if (vars->map_split[k][j] == 'C')
					vars->nb_c++;
				if (vars->map_split[k][j] == 'P')
				{
					vars->map_y = k;
					vars->map_x = j;
				}
				j++;
			}
			k++;
		}
	}
}

void	check_collectibles(t_vars *vars)
{
	if (vars->map_split[vars->map_y][vars->map_x] == 'C')
	{
		vars->nb_c--;
		vars->map_split[vars->map_y][vars->map_x] = '0';
	}
}
