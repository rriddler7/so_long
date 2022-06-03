/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:33:51 by rriddler          #+#    #+#             */
/*   Updated: 2022/01/08 14:34:10 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	foe_moveup(t_solong *game)
{
	game->map[game->foe_y][game->foe_x] = '0';
	game->foe_y--;
	game->map[game->foe_y][game->foe_x] = 'F';
}

void	foe_movedown(t_solong *game)
{
	game->map[game->foe_y][game->foe_x] = '0';
	game->foe_y++;
	game->map[game->foe_y][game->foe_x] = 'F';
}

static void	foe_moveright(t_solong *game)
{
	game->map[game->foe_y][game->foe_x] = '0';
	game->foe_x++;
	game->map[game->foe_y][game->foe_x] = 'F';
}

void	foe_moveleft(t_solong *game)
{
	game->map[game->foe_y][game->foe_x] = '0';
	game->foe_x--;
	game->map[game->foe_y][game->foe_x] = 'F';
}

void	foe_move1(t_solong *game)
{
	if (game->map[game->foe_y - 1][game->foe_x] == '0' && game->flag_foe < 21)
	{
		foe_moveup(game);
		game->flag_foe++;
		draw_map(game);
	}
	else if (game->map[game->foe_y][game->foe_x + 1] == '0'
		&& game->flag_foe < 42)
	{
		foe_moveright(game);
		game->flag_foe++;
		draw_map(game);
	}
	else if (game->map[game->foe_y - 1][game->foe_x] == 'P'
			|| game->map[game->foe_y][game->foe_x + 1] == 'P')
		game_over(game);
	else
	{
		game->flag_move = 0;
		game->flag_foe = 0;
	}
}
