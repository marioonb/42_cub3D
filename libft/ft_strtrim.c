/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:46:36 by mbelorge          #+#    #+#             */
/*   Updated: 2019/11/21 16:44:55 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chercheset(char c, char *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*result;
	char	*resultat;

	i = 0;
	k = 0;
	result = (malloc(sizeof(char) * (ft_strlen(s1) + 1)));
	if (!result)
		return (0);
	while (chercheset(s1[i], (char*)set))
		i++;
	j = ft_strlen(s1) - 1;
	while (chercheset(s1[j], (char*)set))
		j--;
	while (i <= j)
		result[k++] = s1[i++];
	result[k] = '\0';
	resultat = ft_strdup(result);
	free(result);
	if (!resultat)
		return (0);
	return (resultat);
}
