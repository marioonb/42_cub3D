/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_double_tab(char **tab, int lenght)
{
	int	i;

	i = 0;
	while (i < lenght)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_all(t_cub3d *cub3d)
{
	if (cub3d->mlx_ptr && cub3d->win_ptr)
	{
		mlx_clear_window(cub3d->mlx_ptr, cub3d->win_ptr);
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
	}
	free_double_tab(cub3d->old_map.tabmap, cub3d->map.lo);
	free_double_tab(cub3d->map.tabmap, cub3d->map.lo);
	free_orientation(cub3d);
}

void	free_orientation(t_cub3d *cub3d)
{
	if (cub3d->t_so.orientation)
		free(cub3d->t_so.orientation);
	if (cub3d->t_so.path)
		free(cub3d->t_so.path);
	if (cub3d->t_we.orientation)
		free(cub3d->t_we.orientation);
	if (cub3d->t_we.path)
		free(cub3d->t_we.path);
	if (cub3d->t_ea.orientation)
		free(cub3d->t_ea.orientation);
	if (cub3d->t_ea.path)
		free(cub3d->t_ea.path);
	if (cub3d->t_no.orientation != NULL)
		free(cub3d->t_no.orientation);
	if (cub3d->t_no.path != NULL)
		free(cub3d->t_no.path);
	if (cub3d->t_spr.orientation != NULL)
		free(cub3d->t_spr.orientation);
	if (cub3d->t_spr.path != NULL)
		free(cub3d->t_spr.path);
}
