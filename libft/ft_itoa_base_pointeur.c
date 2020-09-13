/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_pointeur.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:13:55 by mbelorge          #+#    #+#             */
/*   Updated: 2020/01/29 12:32:46 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*change_base(unsigned long adr, const char *base)
{
	int				i;
	int				j;
	char			res[9];
	char			*resultat;

	i = 8;
	while ((adr / 16) > 0 || i > 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	resultat = malloc(sizeof(char) * (9 - i + 2));
	j = 0;
	resultat[j] = '0';
	resultat[j + 1] = 'x';
	j = 0;
	while (i < 9)
	{
		resultat[j + 2] = res[i];
		i++;
		j++;
	}
	return (resultat);
}

char				*itoa_base_pointeur(void *p)
{
	unsigned long	adr;
	char const		*base;
	char			*resultat;

	adr = (unsigned long)p;
	base = "0123456789abcdef";
	resultat = change_base(adr, base);
	return (resultat);
}
