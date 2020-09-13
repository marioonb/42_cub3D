/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** parcours de -1 jusqu'a la resolution de l'ecran
** side dist = si la distance avec le mur le plus proche en x est inferieur
** à la distance du mur le plus proche en y
** il faut faire une correction obligatoire / PWD = distance avec le mur
** le plus proche
** Calcule la hauteur de la ligne dessiner à l'ecran (lineHeigth)
** calcule le pixel le plus bas et le plus haut pour remplir la bande actuelle.
*/

static void	dda(t_cub3d *c)
{
	if (c->ray.side_dist_x < c->ray.side_dist_y)
	{
		c->ray.side_dist_x += c->ray.delta_dist_x;
		c->ray.xactual += c->ray.step_x;
		c->ray.side = 0;
	}
	else
	{
		c->ray.side_dist_y += c->ray.delta_dist_y;
		c->ray.yactual += c->ray.step_y;
		c->ray.side = 1;
	}
	if (c->map.tabmap[c->ray.xactual][c->ray.yactual] == '1')
		c->ray.hit = 1;
}

void		raycasting(t_cub3d *c)
{
	c->ray.x = -1;
	while (++c->ray.x <= c->resol.width)
	{
		c->ray.hit = 0;
		init_raycast(c);
		calcul_sidedist(c);
		while (c->ray.hit == 0)
			dda(c);
		if (c->ray.side == 0)
			c->ray.pwd = (c->ray.xactual - c->player.x +
			(1 - c->ray.step_x) / 2) / c->ray.raydir_x;
		else
			c->ray.pwd = (c->ray.yactual - c->player.y +
			(1 - c->ray.step_y) / 2) / c->ray.raydir_y;
		c->ray.line_heigth = (int)(c->resol.heigth / c->ray.pwd);
		c->ray.draw_start = (int)(-c->ray.line_heigth / 2 +
			c->resol.heigth / 2);
		if (c->ray.draw_start < 0)
			c->ray.draw_start = 0;
		c->ray.draw_end = (int)(c->ray.line_heigth / 2 + c->resol.heigth / 2);
		if (c->ray.draw_end >= c->resol.heigth)
			c->ray.draw_end = c->resol.heigth - 1;
		ft_draw_walls(c);
		c->sp.distance_tab[c->ray.x] = c->ray.pwd;
	}
}

/*
** calcul camera et position X pour coordonner la caméra dans l'espace
** camera X -> ratio qui permet de recupérer un valeur entre -1 et 1,
** 0 etant le milieu. possible aussi en ecrivant
** raydir -> On calcule le vecteur, il doit etre perpendiculaire,
** il donne la direction du rayon
** delta dist x = saut en 2 cases de x - longueur de ray coté x et y
** jusqu'au prochain x et y
** attention bien caster en int les actual, pour enlever la decimal,
** si le joueur est en 2,2, on recupere 2.
*/

void		init_raycast(t_cub3d *cub)
{
	cub->ray.camera_x = 2.0 * (double)cub->ray.x /
	(double)cub->resol.width - 1.0;
	cub->ray.raydir_x = cub->player.dir_x + cub->player.plan_x
		* cub->ray.camera_x;
	cub->ray.raydir_y = cub->player.dir_y + cub->player.plan_y
		* cub->ray.camera_x;
	cub->ray.xactual = (int)cub->player.x;
	cub->ray.yactual = (int)cub->player.y;
	cub->ray.delta_dist_x = sqrt(1 + (cub->ray.raydir_y * cub->ray.raydir_y)
		/ (cub->ray.raydir_x * cub->ray.raydir_x));
	cub->ray.delta_dist_y = sqrt(1 + (cub->ray.raydir_x * cub->ray.raydir_x)
		/ (cub->ray.raydir_y * cub->ray.raydir_y));
}

/*
** side dist X distance x la plus proche /
** delta dist x = valeur pour jump d'une valeur à une autre.
** sideX = valeur de l'intersection la plus proche
*/

void		calcul_sidedist(t_cub3d *cub)
{
	if (cub->ray.raydir_x < 0)
	{
		cub->ray.step_x = -1;
		cub->ray.side_dist_x = (cub->player.x - cub->ray.xactual) *
			cub->ray.delta_dist_x;
	}
	else
	{
		cub->ray.step_x = 1;
		cub->ray.side_dist_x = (cub->ray.xactual + 1.0 - cub->player.x) *
			cub->ray.delta_dist_x;
	}
	if (cub->ray.raydir_y < 0)
	{
		cub->ray.step_y = -1;
		cub->ray.side_dist_y = (cub->player.y - cub->ray.yactual) *
			cub->ray.delta_dist_y;
	}
	else
	{
		cub->ray.step_y = 1;
		cub->ray.side_dist_y = (cub->ray.yactual + 1.0 - cub->player.y) *
			cub->ray.delta_dist_y;
	}
}
