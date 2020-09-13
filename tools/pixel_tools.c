/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				image_pixel(t_image *image, int x, int y, int argb)
{
	char			*result;

	result = image->adrr + (y * image->line_l + x * (image->bpx / 8));
	*(unsigned int*)result = argb;
}

unsigned int		my_mlx_pixel_get(t_image img, int x, int y)
{
	unsigned int	color;
	char			*ptr;

	ptr = img.adrr + (y * img.line_l + x * (img.bpx / 8));
	color = *(unsigned int *)ptr;
	return (color);
}

int					create_rgb(int r, int g, int b)
{
	unsigned int	color;

	color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
	return (color);
}
