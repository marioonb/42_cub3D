/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:43:01 by mbelorge          #+#    #+#             */
/*   Updated: 2020/01/02 16:45:14 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** parcours la ligne envoyée et rempli la map,
** si la longueur est plus courte que la plus longue ligne, ajoute un espace
*/

void			fill_map(char **map, char *line, t_map m)
{
	int			i;

	m.y = 0;
	i = 0;
	while (m.y < m.la && m.x <= m.lo)
	{
		if (line[0] == '\0')
		{
			while (m.y < m.la)
			{
				map[m.x][m.y] = '4';
				m.y++;
			}
		}
		else
		{
			if (line[0] == ' ')
				map[m.x][m.y] = '4';
			else
				map[m.x][m.y] = line[0];
			line++;
			m.y++;
		}
	}
	map[m.x][m.y] = '\0';
}

/*
** check la map et envoi la ligne actuelle une fois checkée a
** la fonction fill map
*/

static void		norme(char *ligne, t_cub3d *c)
{
	check_line(ligne, c->map.x);
	fill_map(c->map.tabmap, ligne, c->map);
	c->map.x++;
}

void			check_map(int fd, char *ligne, t_cub3d *c)
{
	int			i;
	char		*line;
	int			ret;

	line = NULL;
	i = 0;
	if (!(c->map.tabmap = malloc(sizeof(c->map.tabmap) * c->map.lo)))
		ft_error_div(7);
	while (i++ < c->map.lo)
		if (!(c->map.tabmap[i - 1] = malloc(c->map.la * sizeof(char) + 1)))
			ft_error_div(7);
	c->map.x = 0;
	norme(ligne, c);
	while ((ret = get_next_line(fd, &line)))
	{
		if (c->map.x < c->map.lo)
			norme(line, c);
		if (!line[0])
			ft_error_div(11);
		free(line);
	}
	free(line);
	check_error_border_map(c->map.tabmap, c->map);
	check_error_inside_map(c->map.tabmap, c->map);
}
