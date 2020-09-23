/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/08/03 18:45:10 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_error_fd(int index, char *s)
{
	mini_printf("Error\n");
	if (index == 1)
		mini_printf("incorrect resolution ou no entry\n");
	else if (index == 2)
		mini_printf("incorrect texture %s or no entry\n", s);
	else if (index == 3)
		mini_printf("Too much element\n");
	else if (index == 4)
		mini_printf("%s missing or syntax error or no mapfile\n", s);
	if (index == 5)
		mini_printf("error malloc - %s", s);
	exit(EXIT_FAILURE);
}

void		ft_error_color_fd(int index, char c)
{
	mini_printf("Error\n");
	if (index == 1)
		mini_printf("color code not numeric or wrong format for %c\n", c);
	if (index == 2)
		mini_printf("color code not entered for %c\n", c);
	else if (index == 4)
		mini_printf("error color code for %c - value between 0 and 255\n", c);
	else if (index == 5)
		mini_printf("too many elements for %c\n", c);
	exit(EXIT_FAILURE);
}

void		ft_error_map(int index, char a, int b, int c)
{
	mini_printf("Error\n");
	if (index == 1)
		mini_printf("wall around map undefined, position : %d, %d or jump \n",
		b, c);
	else if (index == 2)
		mini_printf("map's wall West undefined, line : %d\n", b + 1);
	else if (index == 3)
		mini_printf("map's east undefined, line : %d\n", b + 1);
	else if (index == 4)
		mini_printf("invalid map element %c, line : %d, row :  %d\n",
		a, b + 1, c);
	else if (index == 5)
		mini_printf("no wall around position %d, %d\n", b, c);
	else if (index == 6)
		mini_printf("map not found or invalid\n");
	else if (index == 7)
		mini_printf("multiple position player");
	else if (index == 8)
		mini_printf("player position undefined");
	exit(EXIT_FAILURE);
}

void		ft_error_div(int index)
{
	mini_printf("Error\n");
	if (index == 1)
		mini_printf("unloaded texture\n");
	if (index == 2)
		mini_printf("incorrect image format - enter 64X64\n");
	if (index == 3)
		mini_printf("error argument, enter one map only and option save\n");
	if (index == 4)
		mini_printf("please enter valid map\n");
	if (index == 5)
		mini_printf("bmp no create\n");
	if (index == 6)
		mini_printf("format map invalid - enter .cub extension for map/n");
	if (index == 7)
		mini_printf("error malloc\n");
	if (index == 8)
		mini_printf("error new image no create\n");
	if (index == 9)
		mini_printf("too much element for resolution\n");
	if (index == 10)
		mini_printf("please enter heigth resolution\n");
	if (index == 11)
		mini_printf("jump in map or too much jump after map\n");
	exit(EXIT_FAILURE);
}

void		ft_error_texture(int index, char *s)
{
	mini_printf("Error\n");
	if (index == 1)
		mini_printf("unloaded texture %s or error path\n", s);
	if (index == 2)
		mini_printf("%s is not a correct texture\n", s);
	if (index == 3)
		mini_printf("too much element for %s\n", s);
	exit(EXIT_FAILURE);
}
