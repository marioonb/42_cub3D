/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 09:10:07 by mbelorge          #+#    #+#             */
/*   Updated: 2020/07/02 23:04:23 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				sort_sprite(t_cub3d *cub)
{
	int				i;
	int				j;
	int				tmp;

	i = 0;
	j = cub->sprite_nb - 1;
	while (cub->sprite[i].distwall < cub->sprite[i + 1].distwall)
	{
		tmp = cub->sprite[i].place;
		cub->sprite[i].place = cub->sprite[j].place;
		cub->sprite[j].place = tmp;
		i = i + 1;
		j = j - 1;
	}
}

/*
** // traduire la position de l'image-objet par rapport à la caméra
*/

void				sprite(t_cub3d *cub)
{
	int				i;
	int				stripe;

	i = 0;
	while (i < cub->sprite_nb)
	{
		cub->sprite[i].place = i;
		cub->sprite[i].distwall = ft_power(cub->player.x - cub->sprite[i].x, 2)
			+ ft_power(cub->player.y - cub->sprite[i].y, 2);
		i++;
	}
	sort_sprite(cub);
	i = 0;
	while (i < cub->sprite_nb)
	{
		cub->sp.x = cub->sprite[cub->sprite[i].place].x - cub->player.x;
		cub->sp.y = cub->sprite[cub->sprite[i].place].y - cub->player.y;
		position_sprite(cub);
		calcul_draw_sprite(cub);
		stripe = cub->sp.start_x;
		draw_sprite(cub, stripe, i);
		i++;
	}
	free(cub->sp.distance_tab);
}

/*
** premier calcul requis pour une multiplication matricielle correcte
** de l'écran, ce que Z est en 3D, la distance du sprite au joueur,
** correspondant à sqrt (spriteDistance [i])
** calculer la hauteur du sprite à l'écran
*/

void				position_sprite(t_cub3d *cub)
{
	cub->sp.invdet = 1.0 / (cub->player.plan_x * cub->player.dir_y -
	cub->player.dir_x * cub->player.plan_y);
	cub->sp.transform_x = cub->sp.invdet * (cub->player.dir_y * cub->sp.x -
		cub->player.dir_x * cub->sp.y);
	cub->sp.transform_y = cub->sp.invdet * (-cub->player.plan_y * cub->sp.x
		+ cub->player.plan_x * cub->sp.y);
	cub->sp.screen_x = (int)((cub->resol.width / 2) * (1 + cub->sp.transform_x
		/ cub->sp.transform_y));
	cub->sp.height = abs((int)(cub->resol.heigth / (cub->sp.transform_y)));
}

/*
** utiliser "transformY" au lieu de la distance réelle empêche le fisheye
** calcule le pixel le plus bas et le plus haut pour remplir la bande actuelle
**	+ calculer la largeur du sprite
*/

void				calcul_draw_sprite(t_cub3d *cub)
{
	cub->sp.start_y = -cub->sp.height / 2 + cub->resol.heigth / 2;
	if (cub->sp.start_y < 0)
		cub->sp.start_y = 0;
	cub->sp.end_y = cub->sp.height / 2 + cub->resol.heigth / 2;
	if (cub->sp.end_y >= cub->resol.heigth)
		cub->sp.end_y = cub->resol.heigth - 1;
	cub->sp.width = abs((int)(cub->resol.heigth / cub->sp.transform_y));
	cub->sp.start_x = -cub->sp.width / 2 + cub->sp.screen_x;
	if (cub->sp.start_x < 0)
		cub->sp.start_x = 0;
	cub->sp.end_x = cub->sp.width / 2 + cub->sp.screen_x;
	if (cub->sp.end_x >= cub->resol.width)
		cub->sp.end_x = cub->resol.width - 1;
}

/*
** 	boucle à travers chaque bande verticale du sprite à l'écran
** les conditions dans le if sont:
**			1) il est devant le plan de la caméra pour que
**				vous ne voyiez rien derrière vous
**			2) c'est à l'écran (à gauche)
**			3) c'est à l'écran (à droite)
**	256 et 128 facteurs pour éviter les flotteurs
**	pixel de peinture s'il n'est pas noir, le noir est la couleur invisible
*/

void				draw_sprite(t_cub3d *cub, int stripe, int i)
{
	int				tex_x;
	int				tex_y;
	int				d;
	int				y;
	unsigned int	color;

	while (stripe < cub->sp.end_x)
	{
		tex_x = (int)(256 * (stripe - (-cub->sp.width / 2 + cub->sp.screen_x)) *
			cub->sprite[i].t.width / cub->sp.width) / 256;
		if (cub->sp.transform_y > 0 && stripe > 0 && stripe < cub->resol.width
			&& cub->sp.transform_y < cub->sp.distance_tab[stripe])
		{
			y = cub->sp.start_y - 1;
			while (++y < cub->sp.end_y)
			{
				d = (y) * 256 - cub->resol.heigth * 128 + cub->sp.height * 128;
				tex_y = ((d * cub->sprite[i].t.heigth) / cub->sp.height) / 256;
				color = my_mlx_pixel_get(cub->sprite[i].t.i, tex_x, tex_y);
				if ((color & 0x00FFFFFF) != 0)
					image_pixel(&cub->img, stripe, y, color);
			}
		}
		stripe++;
	}
}
