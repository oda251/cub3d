DRAW_DIR = draw
DRAW_SRCS = $(addprefix $(DRAW_DIR)/, \
	draw_floor_and_ceiling.c \
	draw_wall.c \
	dda_algorithm_utils.c \
	dda_algorithm.c \
	draw_utils.c \
	draw_wall_utils.c \
)

ERROR_DIR = error
ERROR_SRCS = $(addprefix $(ERROR_DIR)/, \
	error.c \
	free.c \
)

HOOK_DIR = hook
HOOK_SRCS = $(addprefix $(HOOK_DIR)/, \
	key_hook.c \
	mouse_hook.c \
	set_hook.c \
	switch_door.c \
)

INIT_DIR = init
INIT_SRCS = $(addprefix $(INIT_DIR)/, \
	convert_map.c \
	init_mlx.c \
	input_data.c \
	parse.c \
	read_cub_file.c \
	util.c \
	validate_data.c \
	init_images.c \
)

UTIL_DIR = util
UTIL_SRCS = $(addprefix $(UTIL_DIR)/, \
	alloc_or_exit.c \
	calc_angle.c \
	calc_vector_int.c \
	calc_vector.c \
	exit_game.c \
)

SRC_DIR = ./src
SRCS = $(addprefix $(SRC_DIR)/, \
	$(DRAW_SRCS) \
	$(ERROR_SRCS) \
	$(HOOK_SRCS) \
	$(INIT_SRCS) \
	$(UTIL_SRCS) \
	main.c \
)
