/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:48:43 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/04 16:20:12 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		ft_close(vars);
	if (keycode == XK_a || keycode == XK_Left)
		move_player(vars, 'x', -1, 'l');
	if (keycode == XK_d || keycode == XK_Right)
		move_player(vars, 'x', 1, 'r');
	if (keycode == XK_w || keycode == XK_Up)
		move_player(vars, 'y', -1, 'r');
	if (keycode == XK_s || keycode == XK_Down)
		move_player(vars, 'y', 1, 'r');
	return (0);
}
