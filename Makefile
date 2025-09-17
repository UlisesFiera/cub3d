NAME		= cub3d

CC			= cc

LIBF		= ./libft/libft.a

STD_FLAGS	= -Wall -Wextra -Werror

MLX_FLAGS	= -Lminilibx/minilibx-linux -lmlx_Linux -lX11 -lXext

SRCS		= 	src/main/main.c \
				src/window/window_manage \
				src/main/free_hand \
				src/main/error_hand \
				src/main/smalloc \

OBJS		= ${SRCS:.c=.o}

REMOVE		= rm -f ${OBJS}

all: deps ${LIBFT} ${NAME}

# deps is a series of commands to ensure the dependencies neccessary to use the mlx are installed
# still linux compatible only

deps:
	@which gcc > /dev/null || { echo "Installing gcc..."; sudo apt-get install -y gcc || echo "Failed to install gcc"; }
	@which make > /dev/null || { echo "Installing make..."; sudo apt-get install -y make || echo "Failed to install make"; }
	@dpkg -s xorg >/dev/null 2>&1 || { echo "Installing xorg..."; sudo apt-get install -y xorg || echo "Failed to install xorg"; }
	@dpkg -s libxext-dev >/dev/null 2>&1 || { echo "Installing libxext-dev..."; sudo apt-get install -y libxext-dev || echo "Failed to install libxext-dev"; }
	@dpkg -s libbsd-dev >/dev/null 2>&1 || { echo "Installing libbsd-dev..."; sudo apt-get install -y libbsd-dev || echo "Failed to install libbsd-dev"; }
	@make -C ./minilibx/minilibx-linux > /dev/null && echo compiling minilibx...

${NAME}:
	@${CC} ${SRCS} ${LIBFT} ${STD_FLAGS} ${MLX_FLAGS} -o ${NAME}
	@echo compiling cub3d...

${LIBFT}:				
	make bonus -C ./libft

clean:					
	@${REMOVE}
	@echo "removing cub3d .o files..."
	@make clean -C ./libft

fclean:	clean
	@rm -f cub3d
	@echo "removing cub3d executable..."
						
re:	fclean all

.PHONY:	all clean fclean re
