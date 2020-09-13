/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2019/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_texture(t_cub3d *c)
{
	if (!(c->t_no.i.img = mlx_xpm_file_to_image(c->mlx_ptr, c->t_no.path,
			&c->t_no.width, &c->t_no.heigth)))
		ft_error_texture(1, "nord");
	c->t_no.i.adrr = mlx_get_data_addr(c->t_no.i.img, &c->t_no.i.bpx,
		&c->t_no.i.line_l, &c->t_no.i.endian);
	if (!(c->t_so.i.img = mlx_xpm_file_to_image(c->mlx_ptr, c->t_so.path,
		&c->t_so.width, &c->t_so.heigth)))
		ft_error_texture(1, "sud");
	c->t_so.i.adrr = mlx_get_data_addr(c->t_so.i.img, &c->t_so.i.bpx,
		&c->t_so.i.line_l, &c->t_so.i.endian);
	if (!(c->t_ea.i.img = mlx_xpm_file_to_image(c->mlx_ptr, c->t_ea.path,
		&c->t_ea.width, &c->t_ea.heigth)))
		ft_error_texture(1, "East");
	c->t_ea.i.adrr = mlx_get_data_addr(c->t_ea.i.img, &c->t_ea.i.bpx,
		&c->t_ea.i.line_l, &c->t_ea.i.endian);
	if (!(c->t_we.i.img = mlx_xpm_file_to_image(c->mlx_ptr, c->t_we.path,
		&c->t_we.width, &c->t_we.heigth)))
		ft_error_texture(1, "Weast");
	c->t_we.i.adrr = mlx_get_data_addr(c->t_we.i.img, &c->t_we.i.bpx,
		&c->t_we.i.line_l, &c->t_we.i.endian);
	get_texture_sprite(c);
}

void	get_texture_sprite(t_cub3d *c)
{
	int	i;

	i = 0;
	while (i < c->sprite_nb)
	{
		if (!(c->sprite[i].t.i.img = mlx_xpm_file_to_image(c->mlx_ptr,
		c->t_spr.path, &c->sprite[i].t.width, &c->sprite[i].t.heigth)))
			ft_error_texture(1, "sprite");
		c->sprite[i].t.i.adrr = mlx_get_data_addr(c->sprite[i].t.i.img,
		&c->sprite[i].t.i.bpx, &c->sprite[i].t.i.line_l,
		&c->sprite[i].t.i.endian);
		i++;
	}
}
