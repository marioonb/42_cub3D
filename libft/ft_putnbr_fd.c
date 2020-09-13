/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:02:55 by mbelorge          #+#    #+#             */
/*   Updated: 2019/11/18 13:03:08 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nombre;

	nombre = n;
	if (n < 0)
	{
		nombre = -n;
		write(fd, "-", 1);
	}
	if (nombre > 9)
	{
		ft_putnbr_fd(nombre / 10, fd);
		ft_putnbr_fd(nombre % 10, fd);
	}
	else
		ft_putchar_fd(nombre + '0', fd);
}
