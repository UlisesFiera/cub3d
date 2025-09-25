CC = cc
CFLAGS = -Wall -Werror -Wextra
#CFLAGS += -fPIE

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
       ft_itoa.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
       ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
       ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_strchr.c \
       ft_split.c ft_strdup.c ft_striter1.c ft_strlcat.c ft_strlcpy.c \
       ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
       ft_strjoin.c ft_substr.c ft_tolower.c ft_toupper.c ft_strtrim.c \
       print_char.c print_digit.c print_ptr.c print_str.c print_un.c \
       print_uphex.c ft_printf.c get_next_line_utils.c get_next_line.c

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
             ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
             ft_lstdelone_bonus.c ft_lstiter_bonus.c \
             ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c

OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) rcs $(NAME) $(OBJS)
	@echo compiling libft...

bonus: $(OBJS) $(BONUS_OBJS)
	@$(AR) rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo compiling libft...

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "removing libft object files..."

fclean: clean
	@rm -f $(NAME)
	@echo "removing libft archive..."

re: fclean all

.PHONY: all clean fclean re bonus
