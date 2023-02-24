/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:18:55 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/04 18:01:11 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	char	*file;
	t_vars	vars;

	file = argv[1];
	check_argc(argc, file, &vars);
	vars.mlx = mlx_init();
	open_window(&vars);
	printf("c'est les bonus\n***************\n");
	close_window(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
