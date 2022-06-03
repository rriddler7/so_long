/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:38:01 by rriddler          #+#    #+#             */
/*   Updated: 2022/01/06 17:38:05 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_solong *game)
{
	if (game->map[game->pl_y - 1][game->pl_x] == '0' && game->pl_y - 1 > 0)
	{
		game->map[game->pl_y][game->pl_x] = '0';
		game->pl_y--;
		game->map[game->pl_y][game->pl_x] = 'P';
		count_steps(game);
	}
	else if (game->map[game->pl_y - 1][game->pl_x] == 'C' && game->pl_y - 1 > 0)
	{
		game->map[game->pl_y][game->pl_x] = '0';
		game->pl_y--;
		game->map[game->pl_y][game->pl_x] = 'P';
		game->score++;
		count_steps(game);
	}
	else if (game->map[game->pl_y - 1][game->pl_x] == 'F' && game->pl_y - 1 > 0)
		game_over(game);
	else if (game->map[game->pl_y - 1][game->pl_x] == 'E'
		&& game->pl_y - 1 > 0 && game->score == game->collect_number)
	{
		count_steps(game);
		printf("You win! Your score is %d.\n", game->score);
		game_end();
	}
	draw_map(game);
}

void	move_down(t_solong *game)
{
	if (game->map[game->pl_y + 1][game->pl_x] == '0'
		&& game->pl_y + 1 < game->height)
	{
		player_movedown(game);
		count_steps(game);
	}
	else if (game->map[game->pl_y + 1][game->pl_x] == 'C'
		&& game->pl_y + 1 < game->height)
	{
		player_movedown(game);
		game->score++;
		count_steps(game);
	}
	else if (game->map[game->pl_y + 1][game->pl_x] == 'F'
		&& game->pl_y + 1 < game->height)
		game_over(game);
	else if (game->map[game->pl_y + 1][game->pl_x] == 'E'
		&& game->pl_y + 1 < game->height && game->score == game->collect_number)
	{
		count_steps(game);
		printf("You win! Your score is %d.\n", game->score);
		game_end();
	}
	draw_map(game);
}

void	move_right(t_solong *game)
{
	if (game->map[game->pl_y][game->pl_x + 1] == '0'
		&& game->pl_x + 1 < game->width)
	{
		player_moveright(game);
		count_steps(game);
	}
	else if (game->map[game->pl_y][game->pl_x + 1] == 'C'
		&& game->pl_x + 1 < game->width)
	{
		player_moveright(game);
		game->score++;
		count_steps(game);
	}
	else if (game->map[game->pl_y][game->pl_x + 1] == 'F'
		&& game->pl_x + 1 < game->width)
		game_over(game);
	else if (game->map[game->pl_y][game->pl_x + 1] == 'E'
		&& game->pl_x + 1 < game->width && game->score == game->collect_number)
	{
		count_steps(game);
		printf("You win! Your score is %d.\n", game->score);
		game_end();
	}
	draw_map(game);
}

void	move_left(t_solong *game)
{
	if (game->map[game->pl_y][game->pl_x - 1] == '0' && game->pl_x - 1 > 0)
	{
		game->map[game->pl_y][game->pl_x] = '0';
		game->pl_x--;
		game->map[game->pl_y][game->pl_x] = 'P';
		count_steps(game);
	}
	else if (game->map[game->pl_y][game->pl_x - 1] == 'C' && game->x - 1 > 0)
	{
		game->map[game->pl_y][game->pl_x] = '0';
		game->pl_x--;
		game->map[game->pl_y][game->pl_x] = 'P';
		game->score++;
		count_steps(game);
	}
	else if (game->map[game->pl_y][game->pl_x - 1] == 'F' && game->x - 1 > 0)
		game_over(game);
	else if (game->map[game->pl_y][game->pl_x - 1] == 'E'
		&& game->pl_x - 1 > 0 && game->score == game->collect_number)
	{
		count_steps(game);
		printf("You win! Your score is %d.\n", game->score);
		game_end();
	}
	draw_map(game);
}
