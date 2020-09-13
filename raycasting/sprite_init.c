/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 09:10:07 by mbelorge          #+#    #+#             */
/*   Updated: 2020/07/02 23:04:23 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				search_number_sprite(t_cub3d *cub3d)
{
	int				x;
	int				y;

	x = 0;
	while (x < cub3d->map.lo)
	{
		y = 0;
		while (y < cub3d->map.la)
		{
			if (cub3d->map.tabmap[x][y] == '2')
				cub3d->sprite_nb++;
			y++;
		}
		x++;
	}
	init_sprite(cub3d);
}

void				init_sprite(t_cub3d *cub3d)
{
	int				x;
	int				y;
	int				i;

	i = 0;
	x = -1;
	if (!(cub3d->sprite = (t_sprite*)calloc(sizeof(t_sprite) *
		cub3d->sprite_nb, 1)))
		ft_error_div(7);
	while (++x < cub3d->map.lo)
	{
		y = -1;
		while (++y < cub3d->map.la)
		{
			if (cub3d->map.tabmap[x][y] == '2')
			{
				cub3d->sprite[i].x = x + 0.5;
				cub3d->sprite[i].y = y + 0.5;
				i++;
			}
		}
	}
}
