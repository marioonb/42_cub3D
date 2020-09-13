/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_struct_cub3d4(t_cub3d *cub3d)
{
	cub3d->resol.width = 0;
	cub3d->resol.heigth = 0;
	cub3d->save = 0;
	cub3d->t_no.orientation = NULL;
	cub3d->t_no.path = NULL;
	cub3d->t_no.i.adrr = NULL;
	cub3d->t_no.width = 0;
	cub3d->t_no.heigth = 0;
	cub3d->t_so.path = NULL;
	cub3d->t_so.orientation = NULL;
	cub3d->t_so.width = 0;
	cub3d->t_so.heigth = 0;
	cub3d->t_we.orientation = NULL;
	cub3d->t_we.path = NULL;
	cub3d->t_we.i.adrr = NULL;
	cub3d->t_we.width = 0;
	cub3d->t_we.heigth = 0;
	cub3d->t_ea.orientation = NULL;
	cub3d->t_ea.path = NULL;
	cub3d->t_ea.i.adrr = NULL;
	cub3d->t_ea.width = 0;
	cub3d->t_ea.heigth = 0;
	cub3d->t_so.i.adrr = NULL;
	cub3d->t_spr.orientation = NULL;
	cub3d->ext = NULL;
}

void		init_struct_cub3d3(t_cub3d *cub3d)
{
	cub3d->t_spr.path = NULL;
	cub3d->t_spr.width = 0;
	cub3d->t_spr.heigth = 0;
	cub3d->color_floor.color_hex = 0;
	cub3d->color_floor.color_hex = 0;
	cub3d->map.tabmap = NULL;
	cub3d->player.x = 0;
	cub3d->player.y = 0;
	cub3d->player.orientation = ' ';
	cub3d->player.dir_x = 0;
	cub3d->player.dir_y = 0;
	cub3d->player.plan_x = 0;
	cub3d->player.plan_y = 0.66;
	cub3d->speed_moove = 0.2;
	cub3d->move.av_rec = 0;
	cub3d->move.left = 0;
	cub3d->move.right = 0;
	cub3d->move.cam = 0;
	cub3d->olddir_x = 0;
	cub3d->olddir_y = 0;
	cub3d->oldplan_x = 0;
	cub3d->oldplan_y = 0;
	cub3d->ray.x = 0;
	cub3d->ray.y = 0;
	init_struct_cub3d4(cub3d);
}

void		init_struct_cub3d2(t_cub3d *cub3d)
{
	cub3d->ray.raydir_y = 0;
	cub3d->ray.xactual = 0;
	cub3d->ray.yactual = 0;
	cub3d->ray.side_dist_x = 0;
	cub3d->ray.side_dist_y = 0;
	cub3d->ray.delta_dist_x = 0;
	cub3d->ray.delta_dist_y = 0;
	cub3d->ray.step_x = 0;
	cub3d->ray.step_y = 0;
	cub3d->ray.pwd = 0;
	cub3d->ray.line_heigth = 0;
	cub3d->ray.draw_start = 0;
	cub3d->ray.draw_end = 0;
	cub3d->ray.side = 0;
	cub3d->ray.wall_x = 0;
	cub3d->ray.textposx = 0;
	cub3d->ray.textposy = 0;
	cub3d->ray.step = 0;
	cub3d->ray.position = 0;
	cub3d->ray.color = 0;
	cub3d->color_floor.orientation = ' ';
	cub3d->color_floor.r = 0;
	cub3d->color_floor.g = 0;
	cub3d->color_floor.b = 0;
	init_struct_cub3d3(cub3d);
}

void		init_struct_cub3d(t_cub3d *cub3d)
{
	cub3d->ray.hit = 0;
	cub3d->color_ceiling.color_hex = 0;
	cub3d->map.lo = 0;
	cub3d->map.la = 0;
	cub3d->map.x = 0;
	cub3d->map.y = 0;
	cub3d->map.tabmap = NULL;
	cub3d->old_map.lo = 0;
	cub3d->old_map.la = 0;
	cub3d->old_map.x = 0;
	cub3d->old_map.y = 0;
	cub3d->old_map.tabmap = NULL;
	cub3d->sprite_nb = 0;
	cub3d->rotate = 0;
	cub3d->ray.camera_x = 0;
	cub3d->ray.raydir_x = 0;
	cub3d->color_floor.color_hex = 0;
	cub3d->color_ceiling.orientation = ' ';
	cub3d->color_ceiling.r = 0;
	cub3d->color_ceiling.g = 0;
	cub3d->color_ceiling.b = 0;
	init_struct_cub3d2(cub3d);
}

/*
**check_fd = check si il y a toutes les infos + reprend la taille de la map
** ft_read_fd = apel des parsing
*/

int			main(int argc, char **argv)
{
	int		fd;
	t_cub3d	cub3d;

	init_struct_cub3d(&cub3d);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7) == 0)
		cub3d.save = 1;
	if (argc == 2 || (argc == 3 && cub3d.save))
	{
		check_arg(&cub3d, argv);
		fd = open(argv[1], O_RDONLY);
		cub3d.map = check_fd(fd);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		ft_read_fd(fd, &cub3d);
		close(fd);
		start_game(&cub3d);
	}
	else if (argc < 2)
		ft_error_div(4);
	else
		ft_error_div(3);
	return (EXIT_SUCCESS);
}
