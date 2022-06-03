/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:04:38 by rriddler          #+#    #+#             */
/*   Updated: 2022/01/06 16:04:58 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	foe_move2(t_solong *game)
{
	if (game->map[game->foe_y + 1][game->foe_x] == '0' && game->flag_foe < 21)
	{
		foe_movedown(game);
		game->flag_foe++;
		draw_map(game);
	}
	else if (game->map[game->foe_y][game->foe_x - 1] == '0'
			&& game->flag_foe < 42)
	{
		foe_moveleft(game);
		game->flag_foe++;
		draw_map(game);
	}
	else if (game->map[game->foe_y + 1][game->foe_x] == 'P'
			|| game->map[game->foe_y][game->foe_x - 1] == 'P')
		game_over(game);
	else
	{
		game->flag_move = 1;
		game->flag_foe = 0;
	}
}

static int	motion_control(int key, t_solong *game)
{
	if (key == 13)
		move_up(game);
	else if (key == 1)
		move_down(game);
	else if (key == 2)
		move_right(game);
	else if (key == 0)
		move_left(game);
	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->window);
		game_end();
	}
	return (game->score);
}

static int	render_next_frame(void *va)
{
	t_solong	*game;

	game = (t_solong *)va;
	game->time = game->time % 8000;
	if (game->foe_number > 0 && game->time == 0)
	{
		if (game->flag_move == 1)
			foe_move1(game);
		else if (game->flag_move == 0)
			foe_move2(game);
	}
	if (game->time == 2000)
		draw_collect2(game);
	if (game->time == 4000)
		draw_collect1(game);
	if (game->time == 6000)
		draw_collect2(game);
	game->time++;
	return (0);
}

static void	init_game(t_solong *game)
{
	game->mlx = mlx_init();
	open_img(game);
	game->window = mlx_new_window(game->mlx, game->width * IMG_SIZE,
			game->height * IMG_SIZE, "Riddler");
}

int	main(int argc, char **argv)
{
	t_solong	game;

	game = (t_solong){0};
	if (!verify_berfile(argc, argv[1]))
		return (1);
	game.map = create_map(argv[1], &game);
	if (!game.map)
		return (2);
	if (!verify_map(game.map, &game))
		exit (1);
	else
		init_game(&game);
	draw_map(&game);
	mlx_key_hook(game.window, motion_control, &game);
	game.time = 1;
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_hook(game.window, 17, 0, game_end, &game);
	mlx_loop(game.mlx);
	return (0);
}
