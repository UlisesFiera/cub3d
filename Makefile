NAME		= 	cub3D

CC			= 	cc

LIBFT		= 	./libft/libft.a
MLX			= 	./minilibx/minilibx-linux/libmlx_Linux.a

STD_FLAGS	= 	-Wall -Wextra -Werror -g
MLX_FLAGS	= 	-Lminilibx/minilibx-linux -lmlx_Linux -lX11 -lXext -lm	# flags for linking mlx deps + math lib
INC_FLAGS   = 	-I./libft -I./minilibx/minilibx-linux -I./src	# include paths (no linker flags here)

SRCS		= 	src/controls/triggers.c \
				src/graphics/init_graphic.c \
				src/graphics/parse_colors.c \
				src/graphics/set_color.c \
				src/graphics/load_textures.c \
				src/graphics/dda_setup.c \
				src/graphics/draw_background.c \
				src/graphics/draw_slice.c \
				src/graphics/get_tex_x.c \
				src/graphics/dda.c \
				src/graphics/render.c \
				src/main/main.c \
				src/main/free_hand.c \
				src/main/err1.c \
				src/main/err2.c \
				src/main/smalloc.c \
				src/main/init_data.c \
				src/main/free_file_data.c \
				src/map/parse_file.c \
				src/map/map_size.c \
				src/map/validate_file.c \
				src/map/init_map.c \
				src/map/parse_elements.c \
				src/map/parse_map.c \
				src/map/check_walls.c \
				src/player/keys_manage.c \
				src/player/move.c \
				src/player/rotation.c \
				src/player/spawn.c \
				src/utils/is_wall.c \
				src/utils/last_char.c \
				src/utils/reset_fd_cursor.c \
				src/utils/tab_reader.c \
				src/utils/rm_tabs.c \
				src/window/window_manage.c \
				src/player/init_player.c \

OBJDIR		= 	build
OBJS		= 	$(patsubst src/%.c,${OBJDIR}/%.o,${SRCS})

REMOVE		= 	rm -f ${OBJS}

RED_DOT		= 	"\033[31m[●]\033[0m"
GREEN_DOT	= 	"\033[32m[●]\033[0m"
YELLOW_DOT	= 	"\033[33m[●]\033[0m"

all: ${MLX} ${LIBFT} ${NAME}

# the MLX rule is a series of commands to ensure the dependencies neccessary to use the mlx are installed
# still linux compatible only

${MLX}:
	@make --no-print-directory -C ./minilibx/minilibx-linux > /dev/null && printf "\r\033[33m[●]\033[0m compiling and installing minilibx deps...\n"
	@which gcc > /dev/null || { printf "\r\033[33m[●]\033[0m installing gcc...\n"; sudo apt-get install -y gcc || printf "\r\033[31m[●]\033[0m failed to install gcc\n"; }
	@which make > /dev/null || { printf "\r\033[33m[●]\033[0m installing make...\n"; sudo apt-get install -y make || printf "\r\033[31m[●]\033[0m failed to install make\n"; }
# @dpkg -s xorg >/dev/null 2>&1 || { printf "\r\033[33m[●]\033[0m installing xorg...\n"; sudo apt-get install -y xorg || printf "\r\033[31m[●]\033[0m failed to install xorg\n"; }
	@dpkg -s libxext-dev >/dev/null 2>&1 || { printf "\r\033[33m[●]\033[0m installing libxext-dev...\n"; sudo apt-get install -y libxext-dev || printf "\r\033[31m[●]\033[0m failed to install libxext-dev\n"; }
	@dpkg -s libbsd-dev >/dev/null 2>&1 || { printf "\r\033[33m[●]\033[0m installing libbsd-dev...\n"; sudo apt-get install -y libbsd-dev || printf "\r\033[31m[●]\033[0m failed to install libbsd-dev\n"; }
	@make --no-print-directory -C ./minilibx/minilibx-linux > /dev/null && printf "\r\033[32m[●]\033[0m compiling and installing minilibx deps...\n"

$(OBJDIR)/%.o: src/%.c
	@printf "\r\033[33m[●]\033[0m compiling cub3D..."
	@mkdir -p $(dir $@)
	@${CC} ${STD_FLAGS} ${INC_FLAGS} -c $< -o $@ \
	|| { printf "\n\033[31m[●]\033[0m Error: cub3D compilation failed!\n"; exit 1; }

${NAME}: ${OBJS}
	@${CC} ${OBJS} ${STD_FLAGS} ${MLX_FLAGS} ${LIBFT} -o ${NAME} \
	|| { printf "\n\033[31m[●]\033[0m Error: cub3D compilation failed!\n"; exit 1; }
	@printf "\r\033[32m[●]\033[0m compiling cub3D...\n"

${LIBFT}:
	@printf "\r\033[33m[●]\033[0m compiling and linking libft..."	
	@make --no-print-directory bonus -C ./libft > /dev/null 2>&1  \
	|| { printf "\n\033[31m[●]\033[0m Error: libft installation failed!\n"; exit 1; }
	@printf "\r\033[32m[●]\033[0m compiling and linking libft...\n"	

clean:
	@printf "\r\033[33m[●]\033[0m removing .o files..."		
	@${REMOVE}
	@make --no-print-directory clean -C ./libft clean > /dev/null 2>&1
	@printf "\r\033[32m[●]\033[0m removing .o files...\n"

fclean:	clean
	@printf "\r\033[33m[●]\033[0m removing executables..."
	@rm -f cub3D
	@rm -rf build
	@make --no-print-directory fclean -C ./libft fclean > /dev/null 2>&1
	@printf "\r\033[32m[●]\033[0m removing executables...\n"
						
re:	fclean all

.PHONY:	all clean fclean re

.DEFAULT:
	@printf "\n\033[31m[●]\033[0m Error: no rule to make target '$@'\n"
	@false