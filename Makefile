include src.mk

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror
TFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

UNAME_S = $(shell uname -s)
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBX_DIR = ./mlx

GNL_DIR = ./get_next_line
SRCS += $(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c

LINKS = -L$(LIBFT_DIR) -lft
ifeq ($(UNAME_S),Linux)
	LINKS += -L$(LIBX_DIR) -lmlx_Linux
	LINKS += -lXext -lX11 -lm
else
	LINKS += -framework OpenGL -framework AppKit
	LINKS += -L$(LIBX_DIR) -lmlx
endif
INCLUDES = -I $(LIBFT_DIR) -I $(GNL_DIR) -I ./include/
ifeq ($(UNAME_S),Linux)
	INCLUDES += -I ./include/linux/
else
	INCLUDES += -I ./include/mac/
endif

all: $(NAME)

$(NAME): $(LIBFT) $(LIBX) $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SRCS) $(LINKS)

test:
	$(CC) $(TFLAGS) $(INCLUDES) -o $(NAME) $(SRCS) $(LINKS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test