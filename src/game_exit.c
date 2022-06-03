/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:36:00 by rriddler          #+#    #+#             */
/*   Updated: 2022/01/08 14:36:06 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_end(void)
{
	printf("The end!\n");
	exit(3);
	return (0);
}

int	game_over(t_solong *game)
{
	printf("Game over!\nYour score is %d.\n", game->score);
	mlx_destroy_window(game->mlx, game->window);
	exit(4);
	return (0);
}
