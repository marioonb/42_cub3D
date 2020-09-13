/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int							screenshot_map(t_cub3d *cub3d)
{
	int						fd;
	static unsigned char	header[54];
	unsigned int			pixel_bytes_per_row;
	int						i;
	t_bmp					img_data[cub3d->resol.heigth][cub3d->resol.width];

	if ((fd = open("cub3d_save.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
		| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0)
		ft_error_div(5);
	pixel_bytes_per_row = cub3d->resol.width * sizeof(t_bmp);
	header_bmp(cub3d, header, pixel_bytes_per_row);
	write(fd, header, 54);
	get_img_data(cub3d, img_data);
	i = 0;
	while (i < cub3d->resol.heigth)
	{
		write(fd, img_data[i], pixel_bytes_per_row);
		i++;
	}
	close(fd);
	ft_putstr("screenshot save\n");
	exit(EXIT_SUCCESS);
}

void						header_bmp(t_cub3d *cub3d, unsigned char header[54],
							unsigned int pixel_bytes_per_row)
{
	unsigned int			*size_of_file;
	unsigned int			*swidth;
	unsigned int			*sheight;

	header[0] = 66;
	header[1] = 77;
	header[10] = 54;
	header[14] = 40;
	header[26] = 1;
	header[28] = 32;
	size_of_file = (unsigned int *)&header[2];
	*size_of_file = 54 + pixel_bytes_per_row * cub3d->resol.heigth;
	swidth = (unsigned int *)&header[18];
	*swidth = cub3d->resol.width;
	sheight = (unsigned int *)&header[22];
	*sheight = -cub3d->resol.heigth;
}

void						get_img_data(t_cub3d *cub3d, t_bmp img_data
							[cub3d->resol.heigth][cub3d->resol.width])
{
	int						x;
	int						y;
	unsigned int			color;

	y = 0;
	while (y < cub3d->resol.heigth)
	{
		x = 0;
		while (x < cub3d->resol.width)
		{
			color = my_mlx_pixel_get(cub3d->img, x, y);
			img_data[y][x].t = get_t(color);
			img_data[y][x].r = get_r(color);
			img_data[y][x].g = get_g(color);
			img_data[y][x].b = get_b(color);
			x++;
		}
		y++;
	}
}
