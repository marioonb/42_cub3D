/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:18:20 by mbelorge          #+#    #+#             */
/*   Updated: 2020/01/03 15:45:53 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*concatene(const char *s1, const char *s2, char *resultat)
{
	int			i;
	int			k;
	int			j;
	char		*chaine;

	chaine = resultat;
	i = 0;
	j = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		chaine[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		chaine[i + j] = s2[j];
		j++;
	}
	chaine[i + j] = '\0';
	return (chaine);
}

char			*ft_strjoinfree(char const *s1, char const *s2)
{
	char		*resultat;

	resultat = (char*)malloc(sizeof(char) * (ft_strlen(s1)
	+ ft_strlen(s2) + 1));
	if (!resultat)
		return (0);
	resultat = concatene(s1, s2, resultat);
	if (s1)
		free((char*)s1);
	return (resultat);
}

void			*ft_toomuch_read(char *memory, int i)
{
	char		*temp;
	int			j;

	j = 0;
	temp = ft_strdup(memory);
	if (memory[i])
	{
		while (memory[i] != '\0')
		{
			temp[j] = memory[i + 1];
			i++;
			j++;
		}
		temp[j] = '\0';
		free(memory);
		memory = ft_strdup(temp);
		free(temp);
	}
	else
	{
		free(memory);
		free(temp);
		memory = NULL;
	}
	return (memory);
}

char			*memorywork(char **line, char *memory)
{
	int			i;

	i = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	*line = ft_substr(memory, 0, i);
	memory = ft_toomuch_read(memory, i);
	return (memory);
}

int				get_next_line(int fd, char **line)
{
	static char	*memory;
	char		*buf;
	int			ret;

	buf = NULL;
	if (!line || fd < 0 || (read(fd, buf, 0) < 0) || BUFFER_SIZE <= 0)
		return (-1);
	if (!memory)
		memory = (char *)ft_calloc(sizeof(char), 1);
	buf = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (!ft_strchr(buf, '\n') && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		memory = ft_strjoinfree(memory, buf);
	}
	memory = memorywork(line, memory);
	free(buf);
	if (ret || memory)
		return (1);
	free(memory);
	return (0);
}
