/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:46:23 by clorcery          #+#    #+#             */
/*   Updated: 2022/06/17 16:31:38 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_file(char *s)
{
	int		fd;
	int		size;
	int		rd;
	char	*buf;

	size = 0;
	buf = malloc(sizeof(char));
	fd = open(s, O_RDONLY);
	if (fd == -1)
		ft_error_1(FD_ERROR, buf);
	rd = 1;
	while (rd > 0)
	{	
		rd = read(fd, buf, 1);
		if (rd == -1)
			ft_error_1(RD_ERROR, buf);
		size++;
	}
	free(buf);
	close(fd);
	return (size);
}

char	*recup_map(char *file_name)
{
	int		fd;
	int		len;
	char	*map;
	int		rd;

	len = check_file(file_name);
	map = malloc(sizeof(char) * len);
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error_1(FD_ERROR, map);
	rd = read(fd, map, len);
	if (rd == -1)
		ft_error_1(RD_ERROR, map);
	if (rd == 0)
		ft_error_2(MAP_VOID, map);
	map[len - 1] = '\0';
	close(fd);
	return (map);
}

char	**recup_map_split(char *file, t_vars *vars)
{
	char	*map;
	int		k;

	k = 0;
	map = recup_map(file);
	vars->map_split = ft_split(map, '\n');
	if (vars->map_split[k] == NULL)
	{
		ft_free_tab_char(vars->map_split);
		ft_error_2(MAP_ERROR, map);
	}
	free(map);
	return (vars->map_split);
}
