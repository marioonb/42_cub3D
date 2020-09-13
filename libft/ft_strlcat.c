/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:15:04 by mbelorge          #+#    #+#             */
/*   Updated: 2019/12/04 11:11:09 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	while (dst[j] != '\0')
		j++;
	i = 0;
	k = 0;
	while (src[i] != '\0' && j + i < dstsize - 1)
	{
		if (dstsize != 0)
			dst[j + i] = src[i];
		i++;
		k++;
	}
	if (dstsize != 0)
		dst[j + i] = '\0';
	while (src[k] != '\0')
		k++;
	if (dstsize < j)
		return (k + dstsize);
	return (j + k);
}
