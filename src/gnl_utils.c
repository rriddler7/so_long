/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:36:41 by rriddler          #+#    #+#             */
/*   Updated: 2022/01/08 14:36:46 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			return ((char *)str + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	int		s;
	char	*dup;
	int		i;

	i = 0;
	s = 0;
	while (src[s] != '\0')
		s++;
	dup = (char *)malloc(sizeof(char) * (s + 1));
	if (dup == NULL)
		return (NULL);
	while (i < s)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j] != '\0')
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*break_line(char **nextline, char **tail)
{
	char	*line_end;
	char	*tmp;

	line_end = NULL;
	if (*tail)
	{
		line_end = ft_strchr(*tail, '\n');
		if (line_end == NULL)
		{
			tmp = *nextline;
			*nextline = ft_strdup(*tail);
			free(tmp);
			free(*tail);
			*tail = NULL;
		}
		else
		{
			*line_end = '\0';
			tmp = *nextline;
			*nextline = ft_strdup(*tail);
			free(tmp);
			ft_strcpy(*tail, ++line_end);
		}
	}
	return (line_end);
}

char	*find_n(char	**line, char *buff, char *line_end, char *tail)
{
	char		*tmp;

	*line_end = '\0';
	tmp = tail;
	tail = ft_strdup(++line_end);
	free(tmp);
	tmp = *line;
	*line = ft_strjoin(*line, buff);
	free(tmp);
	return (tail);
}
