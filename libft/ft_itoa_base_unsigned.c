/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:14:02 by mbelorge          #+#    #+#             */
/*   Updated: 2020/01/03 17:18:25 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			convertletter_un(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char				*ft_itoa_base_unsigned(unsigned int value, int base)
{
	int				i;
	char			*str;
	unsigned int	tmp;

	i = 0;
	tmp = value;
	while (tmp >= (unsigned int)base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		str[i] = convertletter_un(tmp);
		value /= base;
		i--;
	}
	return (str);
}
