/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2019/07/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned char	get_t(unsigned int color)
{
	return (color >> 24);
}

unsigned char	get_r(unsigned int color)
{
	return ((color >> 16) & 0XFF);
}

unsigned char	get_g(unsigned int color)
{
	return ((color >> 8) & 0xFF);
}

unsigned char	get_b(unsigned int color)
{
	return (color & 0XFF);
}
