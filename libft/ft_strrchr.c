/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:24:24 by mbelorge          #+#    #+#             */
/*   Updated: 2019/12/03 12:57:15 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	cherchecaractere(const char *s, int c)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strrchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c && !cherchecaractere(s, c))
			return ((char *)s);
		s++;
	}
	if (!c && !*s)
		return ((char *)s);
	return (0);
}
