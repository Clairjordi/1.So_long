/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:42:57 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/04 17:40:57 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_letter_map(char *file_name, t_vars *vars)
{
	char	*map;
	int		i;

	i = 0;
	map = recup_map(file_name);
	while (map[i])
	{
		if (!(map[i] == '1' || map[i] == '0' || map[i] == 'C'
				|| map[i] == 'P' || map[i] == 'E' || map[i] == '\n'
				|| map[i] == 'B'))
			ft_error_3(MAP_LETTER_ERROR, map, vars);
		i++;
	}
	free(map);
}

void	check_extension(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '.')
		i++;
	if (strncmp(file + i, ".ber", 5) != 0)
		ft_error_2(EXT_ERROR, 0);
}

void	check_letter_c(char *filename, t_vars *vars)
{
	char	*map;
	int		c;
	int		i;

	c = 0;
	i = 0;
	map = recup_map(filename);
	while (map[i])
	{
		if (map[i] == 'C')
			c++;
		i++;
	}
	if (c == 0)
		ft_error_3(LETTER_C_ERROR, map, vars);
	free(map);
}

void	check_letter_e_p(char *filename, t_vars *vars)
{
	char	*map;
	int		i;
	int		f;
	int		e;

	i = 0;
	f = 0;
	e = 0;
	map = recup_map(filename);
	while (map[i])
	{
		if (map[i] == 'P')
			f++;
		if (map[i] == 'E')
			e++;
		if (f > 1 || e > 1)
			ft_error_3(LETTER_E_P_ERROR, map, vars);
		i++;
	}
	if (f == 0 || e == 0)
		ft_error_3(LETTER_E_P_ERROR, map, vars);
	free(map);
}
