/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_element(char *tab)
{
	if (!ft_strstr(tab, "NO"))
		ft_error_fd(4, "NO");
	if (!ft_strstr(tab, "EA"))
		ft_error_fd(4, "EA");
	if (!ft_strstr(tab, "SO"))
		ft_error_fd(4, "SO");
	if (!ft_strstr(tab, "WE"))
		ft_error_fd(4, "WE");
	if (!ft_strstr(tab, "S "))
		ft_error_fd(4, "S");
	if (!ft_strstr(tab, "F "))
		ft_error_fd(4, "F");
	if (!ft_strstr(tab, "C "))
		ft_error_fd(4, "C");
	if (!ft_strstr(tab, "R "))
		ft_error_fd(4, "R");
}

static int	fill_tab_orientation(char *tab, char *line, int i)
{
	if (i > 15)
		ft_error_fd(3, " ");
	tab[i] = line[0];
	tab[i + 1] = line[1];
	i += 2;
	return (i);
}

t_map		check_fd(int fd)
{
	char	*line;
	t_map	m;
	int		i;
	char	*tab;

	i = 0;
	tab = NULL;
	line = NULL;
	if (!(tab = calloc(17, sizeof(char))))
		ft_error_fd(5, "tableau textures");
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_isalpha(line[0]))
			i = fill_tab_orientation(tab, line, i);
		else if (line[0] == '1' || line[0] == ' ')
			m = lenght_map(fd);
		free(line);
	}
	free(line);
	check_element(tab);
	free(tab);
	if (m.lo < 3 || m.la < 3)
		ft_error_map(6, ' ', 0, 0);
	return (m);
}

t_map		lenght_map(int fd)
{
	int		lenght_line_actual;
	t_map	mapstruct;
	char	*line;

	mapstruct.lo = 1;
	mapstruct.la = 0;
	line = NULL;
	while (get_next_line(fd, &line) && line[0] != '\0')
	{
		lenght_line_actual = ft_strlen(line);
		if (lenght_line_actual > mapstruct.la)
			mapstruct.la = lenght_line_actual;
		mapstruct.lo++;
		free(line);
	}
	free(line);
	return (mapstruct);
}

/*
** lit le fd et appel les fonctions de parsing
*/

void		ft_read_fd(int fd, t_cub3d *cub3d)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'R')
			cub3d->resol = resolution_parse(line);
		else if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
			|| line[0] == 'E')
			define_texture(cub3d, line);
		else if (line[0] == 'F' || line[0] == 'C')
			define_color(cub3d, line);
		else if (line[0] == ' ' || line[0] == '1' || line[0] == '0')
			check_map(fd, line, cub3d);
		free(line);
	}
	free(line);
}
