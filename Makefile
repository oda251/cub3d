include src.mk

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror
TFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

UNAME_S = $(shell uname -s)
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = ./get_next_line
SRCS += $(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c

LINKS = -L$(LIBFT_DIR) -lft
INCLUDES = -I $(LIBFT_DIR) -I $(GNL_DIR) -I $(SRC_DIR)/include

ifeq ($(UNAME_S),Linux)
	LIBX_DIR = ./minilibx-linux
	LINKS += -lXext -lX11 -lm
else
	LIBX_DIR = ./minilibx_opengl
	LINKS += -framework OpenGL -framework AppKit
endif
LIBX = $(LIBX_DIR)/libmlx.a
LINKS += -L$(LIBX_DIR) -lmlx
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