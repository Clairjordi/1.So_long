/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:38:25 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/04 17:32:28 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_argc(int ac, char *file_name, t_vars *vars)
{
	char	**tmp;

	if (ac != 2)
		ft_error_2(ARG_ERROR, 0);
	check_extension(file_name);
	tmp = recup_map_split(file_name, vars);
	check_line(tmp, vars);
	check_letter_map(file_name, vars);
	check_letter_c(file_name, vars);
	check_letter_e_p(file_name, vars);
	vars->map_x = 0;
	vars->map_y = 0;
}
