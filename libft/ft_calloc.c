/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:37:19 by mbelorge          #+#    #+#             */
/*   Updated: 2019/11/21 16:04:10 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	int		*pointeur;
	size_t	i;
	int		s;

	s = count * size;
	if (s == 0)
		s = 1;
	i = 0;
	pointeur = malloc(s);
	if (pointeur == NULL)
		return (0);
	ft_bzero(pointeur, s);
	return (pointeur);
}
