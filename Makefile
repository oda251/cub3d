include src.mk

NAME = cub3d

CFLAGS = -Wall -Wextra -Werror
TFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

UNAME_S = $(shell uname -s)
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = ./get_next_line
SRCS += $(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c

LINKS = -L$(LIBFT_DIR) -lft
INCLUDES = -I $(LIBFT_DIR) -I $(GNL_DIR) -I ./include/

ifeq ($(UNAME_S),Linux)
	CC = gcc
	INCLUDES += -I ./include_linux
	LIBX_DIR = ./minilibx-linux
	LINKS += -L$(LIBX_DIR) -lmlx
	LINKS += -lXext -lX11 -lm
else
	CC = cc
	INCLUDES += -I ./include_mac
	LIBX_DIR = ./minilibx_opengl
	LINKS += -framework OpenGL -framework AppKit
	LINKS += -L$(LIBX_DIR) -lmlx
endif
LIBX = $(LIBX_DIR)/libmlx.a
INCLUDES += -I $(LIBX_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(LIBX) $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SRCS) $(LINKS)

test:
	$(CC) $(TFLAGS) $(INCLUDES) -o $(NAME) $(SRCS) $(LINKS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBX):
	make -C $(LIBX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(LIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test