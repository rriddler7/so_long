/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:36:52 by rriddler          #+#    #+#             */
/*   Updated: 2022/01/06 17:37:08 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	fill_from_buff(char	**line, char *buff, int fd)
{
	static char	*tail;
	char		*line_end;
	char		*tmp;
	int			read_bytes;

	line_end = break_line(line, &tail);
	if (line_end)
		return (3);
	read_bytes = read(fd, buff, BUFFER_SIZE);
	while (!line_end && read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		line_end = ft_strchr(buff, '\n');
		if (line_end)
			tail = find_n(line, buff, line_end, tail);
		else
		{
			tmp = *line;
			*line = ft_strjoin(*line, buff);
			free(tmp);
			read_bytes = read(fd, buff, BUFFER_SIZE);
		}
	}
	return (read_bytes);
}

static int	get_next_line(int fd, char **line)
{
	static char	*tail;
	int			read_bytes;
	char		*buff;

	if (read(fd, 0, 0) < 0 || line == NULL || BUFFER_SIZE < 1)
		return (4);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (5);
	*line = ft_strdup("");
	read_bytes = fill_from_buff(line, buff, fd);
	free(buff);
	if (read_bytes > 0 || ft_strlen(tail))
		return (6);
	if (read_bytes < 0 || !(*line))
		return (7);
	return (0);
}

static int	verify_fd(int fd)
{
	if (fd == -1)
	{
		printf("Error: File do not open\n");
		exit (7);
	}
	return (1);
}

static int	count_line(char *berfile, t_solong *data)
{
	int		line_number;
	int		fd;
	int		i;
	char	*line;

	line_number = 0;
	fd = open(berfile, O_RDONLY);
	verify_fd(fd);
	line = NULL;
	i = get_next_line(fd, &line);
	while (i > 0)
	{
		line_number++;
		free(line);
		i = get_next_line(fd, &line);
	}
	line_number++;
	close(fd);
	if (i < 0)
		exit(2);
	free(line);
	data->height = line_number;
	return (line_number);
}

char	**create_map(char *berfile, t_solong *data)
{
	int		line_number;
	char	**map;
	int		fd;
	int		i;
	int		j;

	line_number = count_line(berfile, data);
	map = ft_calloc(line_number, sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(berfile, O_RDONLY);
	j = 0;
	i = get_next_line(fd, &map[j]);
	while (i > 0)
	{
		j++;
		i = get_next_line(fd, &map[j]);
	}
	close(fd);
	if (i < 0)
		exit(3);
	return (map);
}
