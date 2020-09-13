/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			put_ceiling_and_floor(t_cub3d *cub3d)
{
	t_image		img;
	int			x;
	int			y;

	x = -1;
	if (!(img.img = mlx_new_image(cub3d->mlx_ptr, cub3d->resol.width,
		cub3d->resol.heigth)))
		ft_error_div(8);
	img.adrr = mlx_get_data_addr(img.img, &img.bpx, &img.line_l, &img.endian);
	cub3d->img = img;
	while (++x < cub3d->resol.width)
	{
		y = -1;
		while (++y < cub3d->resol.heigth / 2)
			image_pixel(&img, x, y, cub3d->color_ceiling.color_hex);
	}
	x = -1;
	while (++x < cub3d->resol.width)
	{
		y = (cub3d->resol.heigth / 2) - 1;
		while (++y < cub3d->resol.heigth)
			image_pixel(&cub3d->img, x, y, cub3d->color_floor.color_hex);
	}
}

void			ft_draw_walls(t_cub3d *c)
{
	c->ray.y = c->ray.draw_start;
	if (c->ray.side == 0)
		c->ray.wall_x = c->player.y + c->ray.pwd * c->ray.raydir_y;
	else
		c->ray.wall_x = c->player.x + c->ray.pwd * c->ray.raydir_x;
	c->ray.wall_x -= floor((c->ray.wall_x));
	c->ray.textposx = (int)(c->ray.wall_x * (double)(64));
	if (c->ray.side == 0 && c->ray.raydir_x > 0)
		c->ray.textposx = 64 - c->ray.textposx - 1;
	if (c->ray.side == 1 && c->ray.raydir_y < 0)
		c->ray.textposx = 64 - c->ray.textposx - 1;
	c->ray.step = 1.0 * 64 / c->ray.line_heigth;
	c->ray.position = (c->ray.y - c->resol.heigth / 2 +
		c->ray.line_heigth / 2) * c->ray.step;
	while (++c->ray.y < c->ray.draw_end)
		calcul_wall_orientation(c);
}

void			calcul_wall_orientation(t_cub3d *c)
{
	c->ray.textposy = (int)c->ray.position & (64 - 1);
	c->ray.position += c->ray.step;
	if (c->ray.raydir_x > 0 && !c->ray.side)
		c->ray.color = my_mlx_pixel_get(c->t_no.i, c->ray.textposx,
			c->ray.textposy);
	if (c->ray.raydir_x < 0 && !c->ray.side)
		c->ray.color = my_mlx_pixel_get(c->t_so.i, c->ray.textposx,
			c->ray.textposy);
	if ((c->ray.raydir_x > 0 && c->ray.side && c->ray.raydir_y > 0)
		|| (c->ray.side && c->ray.raydir_y > 0))
		c->ray.color = my_mlx_pixel_get(c->t_ea.i, c->ray.textposx,
			c->ray.textposy);
	if ((c->ray.raydir_x > 0 && c->ray.side && c->ray.raydir_y < 0)
		|| (c->ray.side && c->ray.raydir_y < 0))
		c->ray.color = my_mlx_pixel_get(c->t_we.i, c->ray.textposx,
			c->ray.textposy);
	image_pixel(&c->img, c->ray.x, c->ray.y, c->ray.color);
}

void			put_minimap(t_cub3d *cub3d)
{
	int			x;
	int			y;
	int			color;
	t_image		min;

	if (!(min.img = mlx_new_image(cub3d->mlx_ptr,
		(int)cub3d->resol.width / 8, (int)cub3d->resol.heigth / 8)))
		ft_error_div(8);
	min.adrr = mlx_get_data_addr(min.img, &min.bpx, &min.line_l, &min.endian);
	cub3d->minimap = min;
	color = create_rgb(255, 0, 0);
	y = 0;
	while (y < cub3d->map.lo)
	{
		x = 0;
		while (x++ < cub3d->map.la)
			if (cub3d->old_map.tabmap[y][x] == '1')
				image_pixel(&cub3d->minimap, x, y, color);
		y++;
	}
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr,
		cub3d->minimap.img, 0, 0);
}
