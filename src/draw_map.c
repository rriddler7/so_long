/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:37:41 by rriddler          #+#    #+#             */
/*   Updated: 2022/01/06 17:37:46 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_img(t_solong *game)
{
	game->img_size = 64;
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"img/wall.xpm", &game->img_size, &game->img_size);
	game->field = mlx_xpm_file_to_image(game->mlx,
			"img/field.xpm", &game->img_size, &game->img_size);
	game->player_1 = mlx_xpm_file_to_image(game->mlx,
			"img/player_1.xpm", &game->img_size, &game->img_size);
	game->collect_1 = mlx_xpm_file_to_image(game->mlx,
			"img/collect_1.xpm", &game->img_size, &game->img_size);
	game->collect_2 = mlx_xpm_file_to_image(game->mlx,
			"img/collect_2.xpm", &game->img_size, &game->img_size);
	game->foe_1 = mlx_xpm_file_to_image(game->mlx,
			"img/foe_1.xpm", &game->img_size, &game->img_size);
	game->exit_1 = mlx_xpm_file_to_image(game->mlx,
			"img/exit_1.xpm", &game->img_size, &game->img_size);
	game->exit_2 = mlx_xpm_file_to_image(game->mlx,
			"img/exit_2.xpm", &game->img_size, &game->img_size);
}

void	draw_wall(t_solong *game)
{
	game->y = 0;
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < game->width)
		{
			if (game->map[game->y][game->x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall,
					game->x * IMG_SIZE, game->y * IMG_SIZE);
			game->x++;
		}
		game->y++;
	}
}

void	draw_field(t_solong *game)
{
	game->y = 0;
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < game->width)
		{
			if (game->map[game->y][game->x] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->field,
					game->x * IMG_SIZE, game->y * IMG_SIZE);
			game->x++;
		}
		game->y++;
	}
}

void	draw_exit(t_solong *game)
{
	game->y = 0;
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < game->width)
		{
			if (game->map[game->y][game->x] == 'E')
			{
				if (game->score != game->collect_number)
					mlx_put_image_to_window(game->mlx, game->window,
						game->exit_1, game->x * IMG_SIZE, game->y * IMG_SIZE);
				else if (game->score == game->collect_number)
					mlx_put_image_to_window(game->mlx, game->window,
						game->exit_2, game->x * IMG_SIZE, game->y * IMG_SIZE);
			}
			game->x++;
		}
		game->y++;
	}
}

void	draw_player1(t_solong *game)
{
	game->y = 0;
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < game->width)
		{
			if (game->map[game->y][game->x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, game->player_1,
					game->x * IMG_SIZE, game->y * IMG_SIZE);
			game->x++;
		}
		game->y++;
	}
}
