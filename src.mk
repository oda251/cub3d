DRAW_DIR = draw
DRAW_SRCS = $(addprefix $(DRAW_DIR)/, \
	draw_floor_and_ceiling.c \
	draw_wall.c \
	dda_algorithm_utils.c \
	dda_algorithm.c \
	draw_utils.c \
	draw_wall_utils.c \
)

HOOK_DIR = hook
HOOK_SRCS = $(addprefix $(HOOK_DIR)/, \
	handle_door.c \
	key_pressed_hook.c \
	key_released_hook.c \
	loop_hook.c \
	mouse_hook.c \
	move_player.c \
	reflect_input.c \
	rotate_angle.c \
	set_hook.c \
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
)

RENDER_DIR = render
RENDER_SRCS = $(addprefix $(RENDER_DIR)/, \
	cast_ray.c \
	dda_handler.c \
	put_pixel.c \
	render_background.c \
	render_minimap.c \
	render_wall.c \
)

ERROR_DIR = error
ERROR_SRCS = $(addprefix $(ERROR_DIR)/, \
	error.c \
)

UTIL_DIR = util
UTIL_SRCS = $(addprefix $(UTIL_DIR)/, \
	alloc_or_exit.c \
	calc_angle.c \
	calc_vector_int.c \
	calc_vector.c \
	is_door.c \
	exit_game.c \
	time_handler.c \
)

SRC_DIR = ./src
SRCS = $(addprefix $(SRC_DIR)/, \
	$(HOOK_SRCS) \
	$(INIT_SRCS) \
	$(RENDER_SRCS) \
	$(ERROR_SRCS) \
	$(UTIL_SRCS) \
	main.c \
)
