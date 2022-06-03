/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:10:30 by rriddler          #+#    #+#             */
/*   Updated: 2022/01/08 16:10:34 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_steps(t_solong *game)
{
	game->steps++;
	printf("Number of steps: %d.\n", game->steps);
}

void	player_movedown(t_solong *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->pl_y++;
	game->map[game->pl_y][game->pl_x] = 'P';
}

void	player_moveright(t_solong *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->pl_x++;
	game->map[game->pl_y][game->pl_x] = 'P';
}
