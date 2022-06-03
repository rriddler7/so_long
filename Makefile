NAME		= so_long

FLAGS		= -Wall -Wextra -Werror -I./$(HEADER)

SRC			= src/so_long.c src/read_map.c src/lft_utils.c\
			src/gnl_utils.c src/check_file.c src/check_map.c \
			src/draw_map.c src/draw_map2.c src/steps_number.c\
			src/game_exit.c src/player_move.c src/player_move2.c\
			src/foe_move.c

HEADER		= header/

OBJ			= $(SRC:.c=.o)

%.o: %.c Makefile ./header/so_long.h
		gcc $(FLAGS) -Imlx -c $< -o $@

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
		gcc -g -lmlx -framework OpenGL -framework AppKit $^ -o $@

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus
