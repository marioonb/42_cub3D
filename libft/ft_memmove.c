/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:58:15 by mbelorge          #+#    #+#             */
/*   Updated: 2019/12/03 12:53:07 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*source;

	if (n != 0)
	{
		if (dst <= src)
			ft_memcpy(dst, src, n);
		else
		{
			dest = (unsigned char*)dst;
			source = (unsigned char*)src;
			i = n;
			while (i-- != 0)
			{
				dest[i] = source[i];
			}
		}
	}
	return (dst);
}
