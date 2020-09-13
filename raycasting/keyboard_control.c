/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2019/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			key_control(int key, t_cub3d *cub3d)
{
	cub3d->speed_moove = 0.2;
	if (key == KEY_W)
		cub3d->move.av_rec = 1;
	if (key == KEY_S)
		cub3d->move.av_rec = -1;
	if (key == KEY_D)
		cub3d->move.right = 1;
	if (key == KEY_A)
		cub3d->move.left = 1;
	if (key == KEY_LEFT || key == KEY_RIGHT)
	{
		cub3d->move.cam = 1;
		if (key == KEY_LEFT)
			cub3d->rotate = 0.1;
		else
			cub3d->rotate = -0.1;
	}
	if (key == ECHAP)
		close_cross(cub3d);
	return (0);
}

int			key_control2(int key, t_cub3d *cub3d)
{
	if (key == KEY_W)
		cub3d->move.av_rec = 0;
	if (key == KEY_S)
		cub3d->move.av_rec = 0;
	if (key == KEY_D)
		cub3d->move.right = 0;
	if (key == KEY_A)
		cub3d->move.left = 0;
	if (key == KEY_LEFT || key == KEY_RIGHT)
		cub3d->move.cam = 0;
	if (key == ECHAP)
		close_cross(cub3d);
	return (0);
}

int			close_cross(t_cub3d *cub3d)
{
	free_all(cub3d);
	exit(EXIT_SUCCESS);
}
