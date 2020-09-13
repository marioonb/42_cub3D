/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:17:40 by mbelorge          #+#    #+#             */
/*   Updated: 2019/12/03 10:29:22 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *resultat;

	resultat = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!resultat)
		return (0);
	ft_strlcpy(resultat, s1, ft_strlen(s1) + 1);
	return (resultat);
}
