/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:48:43 by clorcery          #+#    #+#             */
/*   Updated: 2022/06/27 18:14:01 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		ft_close(vars);
	if (keycode == XK_a)
		move_player(vars, 'x', -1, 'l');
	if (keycode == XK_d)
		move_player(vars, 'x', 1, 'r');
	if (keycode == XK_w)
		move_player(vars, 'y', -1, 0);
	if (keycode == XK_s)
		move_player(vars, 'y', 1, 0);
	return (0);
}
