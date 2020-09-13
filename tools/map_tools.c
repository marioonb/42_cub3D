/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_rev_char_tab(char *tab, int size)
{
	int		i;
	int		j;
	char	temp;

	j = size - 1;
	i = 0;
	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i = i + 1;
		j = j - 1;
	}
}

void		inv(t_cub3d *cub3d)
{
	char	*tmp;
	int		y;

	y = 0;
	while (y < cub3d->map.lo)
	{
		tmp = ft_strdup(cub3d->map.tabmap[y]);
		ft_rev_char_tab(tmp, cub3d->map.la);
		ft_strcpy(cub3d->map.tabmap[y], tmp);
		y++;
		free(tmp);
	}
}

void		save_original_map(t_cub3d *c)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	if (!(c->old_map.tabmap = malloc(sizeof(c->old_map.tabmap) * c->map.la)))
		ft_error_div(7);
	while (i++ < c->map.lo)
		if (!(c->old_map.tabmap[i - 1] = malloc(sizeof(*c->old_map.tabmap) *
			c->map.lo)))
			ft_error_div(7);
	x = 0;
	while (x < c->map.lo)
	{
		y = 0;
		while (y < c->map.la)
		{
			c->old_map.tabmap[x][y] = c->map.tabmap[x][y];
			y++;
		}
		x++;
	}
}
