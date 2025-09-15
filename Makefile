NAME		= cub3d

CC			= cc

LIBF		= ./libft/libft.a

STD_FLAGS	= -Wall -Wextra -Werror

MLX_FLAGS	= -Lminilibx/minilibx-linux -lmlx_Linux -lX11 -lXext

SRCS		= src/main/main.c

OBJS		= ${SRCS:.c=.o}

REMOVE		= rm -f ${OBJS}

all: ${LIBFT} ${NAME}

${NAME}:
	${CC} ${SRCS} ${LIBFT} ${STD_FLAGS} ${MLX_FLAGS} -o ${NAME}

${LIBFT}:				
	make bonus -C ./libft

clean:					
	${REMOVE}
	make clean -C ./libft

fclean:	clean
	make fclean -C ./libft
	rm -f cub3d
						
re:	fclean all

.PHONY:	all clean fclean re
