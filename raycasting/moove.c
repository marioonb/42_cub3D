/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	player_stop(t_cub3d *cub3d, int x, int y)
{
	if ((cub3d->map.tabmap[x][y] == '1') ||
		(cub3d->map.tabmap[x][y] == '2'))
		return (0);
	else
		return (1);
}

void		ft_left_right(t_cub3d *cub3d)
{
	double	tmp1;
	double	tmp2;

	tmp1 = cub3d->player.x;
	tmp2 = cub3d->player.y;
	if (cub3d->move.right == 1)
	{
		cub3d->player.x += cub3d->player.plan_x * cub3d->speed_moove;
		if (!player_stop(cub3d, (int)cub3d->player.x, (int)cub3d->player.y))
			cub3d->player.x = tmp1;
		cub3d->player.y += cub3d->player.plan_y * cub3d->speed_moove;
		if (!player_stop(cub3d, (int)cub3d->player.x, (int)cub3d->player.y))
			cub3d->player.y = tmp2;
	}
	if (cub3d->move.left == 1)
	{
		cub3d->player.x -= cub3d->player.plan_x * cub3d->speed_moove;
		if (!player_stop(cub3d, (int)cub3d->player.x, (int)cub3d->player.y))
			cub3d->player.x = tmp1;
		cub3d->player.y -= cub3d->player.plan_y * cub3d->speed_moove;
		if (!player_stop(cub3d, (int)cub3d->player.x, (int)cub3d->player.y))
			cub3d->player.y = tmp2;
	}
}

void		ft_rotate_cam(t_cub3d *cub3d)
{
	if (cub3d->move.cam == 1)
	{
		cub3d->olddir_x = cub3d->player.dir_x;
		cub3d->player.dir_x = cub3d->player.dir_x * cos(-cub3d->rotate) -
			cub3d->player.dir_y * sin(-cub3d->rotate);
		cub3d->player.dir_y = cub3d->olddir_x * sin(-cub3d->rotate) +
			cub3d->player.dir_y * cos(-cub3d->rotate);
		cub3d->oldplan_x = cub3d->player.plan_x;
		cub3d->player.plan_x = cub3d->player.plan_x * cos(-cub3d->rotate) -
			cub3d->player.plan_y * sin(-cub3d->rotate);
		cub3d->player.plan_y = cub3d->oldplan_x * sin(-cub3d->rotate) +
			cub3d->player.plan_y * cos(-cub3d->rotate);
	}
}

void		ft_up_and_down(t_cub3d *cub3d)
{
	double	tmpx;
	double	tmpy;

	tmpx = cub3d->player.x;
	tmpy = cub3d->player.y;
	if (cub3d->move.av_rec != 0)
	{
		cub3d->player.x = cub3d->player.x + (cub3d->speed_moove *
			cub3d->player.dir_x) * cub3d->move.av_rec;
		if (!player_stop(cub3d, cub3d->player.x, cub3d->player.y))
			cub3d->player.x = tmpx;
		cub3d->player.y = cub3d->player.y + (cub3d->speed_moove *
			cub3d->player.dir_y) * cub3d->move.av_rec;
		if (!player_stop(cub3d, cub3d->player.x, cub3d->player.y))
			cub3d->player.y = tmpy;
	}
}
