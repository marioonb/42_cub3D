/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:14:34 by mbelorge          #+#    #+#             */
/*   Updated: 2020/01/03 16:14:36 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr(int nb)
{
	unsigned int	nombre;

	nombre = nb;
	if (nb < 0)
	{
		nombre = -nb;
		write(1, "-", 1);
	}
	if (nombre > 9)
	{
		ft_putnbr(nombre / 10);
		ft_putnbr(nombre % 10);
	}
	else
		ft_putchar(nombre + '0');
}
