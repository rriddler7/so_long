/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:39:16 by rriddler          #+#    #+#             */
/*   Updated: 2022/01/06 17:39:28 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/mman.h>

# define BUFFER_SIZE 2
# define IMG_SIZE 64

typedef struct s_solong
{
	void	*mlx;
	void	*window;
	int		x;
	int		y;
	int		width;
	int		height;
	int		player_number;
	int		foe_number;
	int		exit_number;
	int		collect_number;
	int		size_y;
	int		size_x;
	int		img_size;
	int		pl_y;
	int		pl_x;
	int		foe_y;
	int		foe_x;
	char	**map;
	void	*wall;
	void	*field;
	void	*player_1;
	void	*collect_1;
	void	*collect_2;
	void	*foe_1;
	void	*exit_1;
	void	*exit_2;
	int		score;
	int		steps;
	int		flag_foe;
	char	flag_move;
	int		time;
}				t_solong;

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int ch);
char	*break_line(char **nextline, char **tail);
char	*find_n(char	**line, char *buff, char *line_end, char *tail);
char	**create_map(char *berfile, t_solong *data);
int		verify_berfile(int argc, char *berfile);
void	count_characters(char **map, t_solong *game);
void	count_foe(char **map, t_solong *game);
int		verify_map(char **map, t_solong *data);
void	open_img(t_solong *game);
void	draw_wall(t_solong *game);
void	draw_field(t_solong *game);
void	draw_exit(t_solong *game);
void	draw_player1(t_solong *game);
void	draw_collect1(t_solong *game);
void	draw_collect2(t_solong *game);
void	steps_number(t_solong *game);
void	draw_map(t_solong *game);
void	count_steps(t_solong *game);
void	player_movedown(t_solong *game);
void	player_moveright(t_solong *game);
void	move_up(t_solong *game);
void	move_down(t_solong *game);
void	move_right(t_solong *game);
void	move_left(t_solong *game);
void	foe_movedown(t_solong *game);
void	foe_moveleft(t_solong *game);
void	foe_move1(t_solong *game);
int		game_end(void);
int		game_over(t_solong *game);

#endif
