/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		check_arg(t_cub3d *cub3d, char **argv)
{
	if (ft_strlen(argv[1]) < 4)
		ft_error_div(6);
	if ((cub3d->ext = ft_substr(argv[1], ft_strlen(argv[1]) - 4,
		ft_strlen(argv[1]))) && ft_strncmp(cub3d->ext, ".cub", 4) != 0)
		ft_error_div(6);
	free(cub3d->ext);
}

/*
** verifie que le path commence bien par un point et que le format est xpm
*/

void		check_path(char *path, char *s)
{
	char	*temp;

	temp = NULL;
	path++;
	if (!ft_strchr(path, '.'))
		ft_error_fd(2, s);
	while (path[0] != '.')
		path++;
	temp = ft_substr(path, 0, 5);
	if (ft_strncmp(temp, ".xpm", 5) != 0)
		ft_error_fd(2, s);
	free(temp);
}

void		check_error_resolution(t_resol *resolution)
{
	if (!resolution->width || !resolution->heigth)
		ft_error_fd(1, " ");
	if (resolution->width > 2560)
		resolution->width = 2560;
	if (resolution->heigth > 1440)
		resolution->heigth = 1440;
}

void		check_color(t_color color)
{
	if (color.r > 255 || color.g > 255 || color.b > 255)
		ft_error_color_fd(4, color.orientation);
	if (color.r < 0 || color.g < 0 || color.b < 0)
		ft_error_color_fd(4, color.orientation);
}

void		check_color2(char *buff, char c)
{
	if (buff == NULL)
		ft_error_color_fd(2, c);
	if (!ft_isnumber(buff))
		ft_error_color_fd(1, c);
}
