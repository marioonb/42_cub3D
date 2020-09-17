/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/08/03 18:58:33 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				define_texture(t_cub3d *cub3d, char *line)
{
	if (line[0] == 'N')
		cub3d->t_no = texture_parse(line);
	else if (line[0] == 'W')
		cub3d->t_we = texture_parse(line);
	else if (line[0] == 'E')
		cub3d->t_ea = texture_parse(line);
	else if (line[0] == 'S')
	{
		if (line[1] == 'O')
			cub3d->t_so = texture_parse(line);
		else
			cub3d->t_spr = texture_parse(line);
	}
}

t_texture			texture_parse(char *line)
{
	t_texture		text;
	char			**result;

	result = NULL;
	if (ft_strlen(line) <= 2)
		ft_error_texture(1, line);
	result = ft_split(line, ' ');
	text.orientation = ft_strdup(result[0]);
	if (ft_strlen(text.orientation) > 2)
		ft_error_texture(2, text.orientation);
	text.path = ft_strdup(result[1]);
	if (!result[2])
	{
		check_path(result[1], result[0]);
		free_double_tab(result, 2);
	}
	else
		ft_error_texture(3, text.orientation);
	return (text);
}

void				define_color(t_cub3d *cub3d, char *line)
{
	if (line[0] == 'F')
		cub3d->color_floor = color_parse(line);
	else if (line[0] == 'C')
		cub3d->color_ceiling = color_parse(line);
}

t_color				color_parse(char *line)
{
	t_color			color;
	char			**buffer;

	buffer = NULL;
	color.orientation = line[0];
	line++;
	while (line[0] == ' ')
		line++;
	buffer = ft_split(line, ',');
	check_color2(buffer[0], color.orientation);
	check_color2(buffer[1], color.orientation);
	check_color2(buffer[2], color.orientation);
	color.r = ft_atoi(buffer[0]);
	color.g = ft_atoi(buffer[1]);
	color.b = ft_atoi(buffer[2]);
	if (!buffer[3])
	{
		check_color(color);
		color.color_hex = create_rgb(color.r, color.g, color.b);
		free_double_tab(buffer, 3);
	}
	else
		ft_error_color_fd(5, color.orientation);
	return (color);
}

t_resol				resolution_parse(char *line)
{
	int				i;
	char			**result;
	t_resol			resolution;

	i = 0;
	result = ft_split(line, ' ');
	if (!result[1])
		ft_error_div(10);
	resolution.width = ft_atoi(result[1]);
	if (!result[2])
		ft_error_div(10);
	resolution.heigth = ft_atoi(result[2]);
	if (!result[3])
	{
		check_error_resolution(&resolution);
		free_double_tab(result, 3);
	}
	else
		ft_error_texture(3, "R");
	return (resolution);
}
