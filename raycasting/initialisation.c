/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2019/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_play_game(t_cub3d *cub)
{
	put_ceiling_and_floor(cub);
	ft_up_and_down(cub);
	ft_left_right(cub);
	ft_rotate_cam(cub);
	if (!(cub->sp.distance_tab = ft_calloc(sizeof(double*),
	cub->resol.width + 1)))
		return (-1);
	raycasting(cub);
	sprite(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr,
	cub->img.img, 0, 0);
	if (cub->save)
		screenshot_map(cub);
	mlx_destroy_image(cub->mlx_ptr, cub->img.img);
	return (0);
}

void		start_game(t_cub3d *cub3d)
{
	cub3d->mlx_ptr = mlx_init();
	cub3d->win_ptr = mlx_new_window(cub3d->mlx_ptr, cub3d->resol.width,
		cub3d->resol.heigth, "cub3d");
	save_original_map(cub3d);
	inv(cub3d);
	search_player(cub3d);
	search_number_sprite(cub3d);
	get_texture(cub3d);
	mlx_hook(cub3d->win_ptr, 2, 1L << 0, key_control, cub3d);
	mlx_hook(cub3d->win_ptr, 3, 1L << 1, key_control2, cub3d);
	mlx_hook(cub3d->win_ptr, 17, 0L, close_cross, cub3d);
	mlx_loop_hook(cub3d->mlx_ptr, ft_play_game, cub3d);
	mlx_loop(cub3d->mlx_ptr);
}

void		search_player(t_cub3d *cub3d)
{
	int		x;
	int		y;
	int		compt;

	compt = 0;
	x = -1;
	while (++x < cub3d->map.lo)
	{
		y = -1;
		while (++y < cub3d->map.la)
		{
			if (ft_isalpha(cub3d->map.tabmap[x][y]))
			{
				cub3d->player.orientation = cub3d->map.tabmap[x][y];
				cub3d->player.x = x + 0.5;
				cub3d->player.y = y + 0.5;
				compt++;
			}
			if (compt > 1)
				ft_error_map(7, ' ', 0, 0);
		}
	}
	if (cub3d->player.orientation == ' ')
		ft_error_map(8, ' ', 0, 0);
	ft_position_initial(cub3d);
}

void		ft_position_initial(t_cub3d *cub3d)
{
	if (cub3d->player.orientation == 'W')
	{
		cub3d->player.dir_x = 0.0;
		cub3d->player.dir_y = 1.0;
	}
	else if (cub3d->player.orientation == 'S')
	{
		cub3d->player.dir_x = 1.0;
		cub3d->player.dir_y = 0.0;
	}
	else if (cub3d->player.orientation == 'E')
	{
		cub3d->player.dir_x = 0.0;
		cub3d->player.dir_y = -1.0;
	}
	else if (cub3d->player.orientation == 'N')
	{
		cub3d->player.dir_x = -1.0;
		cub3d->player.dir_y = 0.0;
	}
	cub3d->player.plan_x = -0.66 * cub3d->player.dir_y;
	cub3d->player.plan_y = 0.66 * cub3d->player.dir_x;
}
