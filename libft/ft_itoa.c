/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:02:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/01/03 17:15:21 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sizenum(int n)
{
	int		i;

	i = 1;
	if (n < 0)
		n = n * -1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*chaine;
	int		nombre;
	int		i;

	i = sizenum(n);
	nombre = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		nombre = nombre * -1;
		i = i + 1;
	}
	if (!(chaine = malloc(i + 1)))
		return (0);
	if (i > 0)
		chaine[i] = '\0';
	while (i-- > 0)
	{
		chaine[i] = nombre % 10 + '0';
		nombre = nombre / 10;
	}
	if (n < 0)
		chaine[0] = '-';
	return (chaine);
}
