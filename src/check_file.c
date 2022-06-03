/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:28:47 by rriddler          #+#    #+#             */
/*   Updated: 2022/01/08 14:28:53 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	verify_fileextens(char *extens, char *ber)
{
	int	extens_len;
	int	ber_len;

	extens_len = ft_strlen(extens);
	ber_len = ft_strlen(ber);
	if (extens_len <= ber_len)
		return (0);
	extens += extens_len - ber_len;
	while (*extens)
	{
		if (*extens != *ber)
			return (0);
		extens++;
		ber++;
	}
	return (1);
}

int	verify_berfile(int argc, char *berfile)
{
	if (argc < 2)
	{
		printf("Error: no map\n");
		return (0);
	}
	if (argc > 2)
		printf("Warning: more than two maps\n");
	if (!verify_fileextens(berfile, ".ber"))
	{
		printf("Error: not a .ber file\n");
		return (0);
	}
	return (1);
}

void	count_characters(char **map, t_solong *game)
{
	game->y = 0;
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < (int)ft_strlen(map[0]))
		{
			if (map[game->y][game->x] == 'P')
			{
				game->player_number++;
				game->pl_y = game->y;
				game->pl_x = game->x;
			}
			if (map[game->y][game->x] == 'E')
				game->exit_number++;
			if (map[game->y][game->x] == 'C')
				game->collect_number++;
			game->x++;
		}
		game->y++;
	}
}

void	count_foe(char **map, t_solong *game)
{
	game->y = 0;
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < (int)ft_strlen(map[0]))
		{
			if (map[game->y][game->x] == 'F')
			{
				game->foe_number++;
				game->foe_y = game->y;
				game->foe_x = game->x;
			}
			game->x++;
		}
		game->y++;
	}
}
