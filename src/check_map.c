/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:37:20 by rriddler          #+#    #+#             */
/*   Updated: 2022/01/06 17:37:27 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	verify_unpos_characters(char **map, t_solong *data)
{
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < (int)ft_strlen(map[0]))
		{
			if (map[data->y][data->x] != '1' && map[data->y][data->x] != '0'
				&& map[data->y][data->x] != 'P' && map[data->y][data->x] != 'C'
				&& map[data->y][data->x] != 'E' && map[data->y][data->x] != 'F')
			{
				printf("Error: unpossible characters\n");
				return (0);
			}
			data->x++;
		}
		data->y++;
	}
	return (1);
}

static int	verify_characters(char **map, t_solong *data)
{
	count_characters(map, data);
	if (data->player_number > 1)
	{
		printf("Error: more than one player\n");
		return (0);
	}
	if (data->player_number < 1)
	{
		printf("Error: no player\n");
		return (0);
	}
	if (data->exit_number < 1)
	{
		printf("Error: no exit\n");
		return (0);
	}
	if (data->collect_number < 1)
	{
		printf("Error: no collectible\n");
		return (0);
	}
	return (1);
}

static int	verify_foe(char **map, t_solong *data)
{
	count_foe(map, data);
	if (data->foe_number > 1)
	{
		printf("Error: more than one foe\n");
		return (0);
	}
	return (1);
}

static int	verify_wall(char **map, t_solong data)
{
	data.size_y = data.height;
	data.size_x = ft_strlen(map[0]);
	data.y = 0;
	while (data.y < data.height)
	{
		data.x = 0;
		while (data.x < (int)ft_strlen(map[0]))
		{
			if (data.y == 0 || data.x == 0 || data.y == data.size_y - 1
				|| data.x == data.size_x - 1)
			{
				if (map[data.y][data.x] != '1')
				{
					printf("Error: the map is not closed by walls\n");
					return (0);
				}
			}
			data.x++;
		}
		data.y++;
	}
	return (1);
}

int	verify_map(char **map, t_solong *data)
{
	data->y = 0;
	while (data->y < data->height)
	{
		if (ft_strlen(map[data->y]) != ft_strlen(map[0]))
		{
			printf("Error: the map is not rectangular\n");
			return (0);
		}
		data->y++;
	}
	data->width = ft_strlen(map[0]);
	if (!verify_unpos_characters(map, data) || !verify_characters(map, data)
		|| !verify_wall(map, *data) || !verify_foe(map, data))
		return (0);
	return (1);
}
