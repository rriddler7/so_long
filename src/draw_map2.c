/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:29:34 by rriddler          #+#    #+#             */
/*   Updated: 2022/01/08 14:29:37 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_collect1(t_solong *game)
{
	game->y = 0;
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < game->width)
		{
			if (game->map[game->y][game->x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->window,
					game->collect_1, game->x * IMG_SIZE, game->y * IMG_SIZE);
			}
			game->x++;
		}
		game->y++;
	}
}

void	draw_collect2(t_solong *game)
{
	game->y = 0;
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < game->width)
		{
			if (game->map[game->y][game->x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->window,
					game->collect_2, game->x * IMG_SIZE, game->y * IMG_SIZE);
			}
			game->x++;
		}
		game->y++;
	}
}

static void	draw_foe(t_solong *game)
{
	game->y = 0;
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < game->width)
		{
			if (game->map[game->y][game->x] == 'F')
			{
				mlx_put_image_to_window(game->mlx, game->window, game->foe_1,
					game->x * IMG_SIZE, game->y * IMG_SIZE);
			}
			game->x++;
		}
		game->y++;
	}
}

void	draw_map(t_solong *game)
{
	mlx_clear_window(game->mlx, game->window);
	draw_wall(game);
	draw_field(game);
	draw_exit(game);
	draw_collect1(game);
	draw_player1(game);
	draw_foe(game);
	steps_number(game);
}
