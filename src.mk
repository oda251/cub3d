INIT_DIR = init
INIT_SRCS = $(addprefix $(INIT_DIR)/, \
	convert_map.c \
	input_data.c \
	parse.c \
	read_cub_file.c \
	validate_data.c \
	util.c \
)

ERROR_DIR = error
ERROR_SRCS = $(addprefix $(ERROR_DIR)/, \
	error.c \
)

UTIL_DIR = util
UTIL_SRCS = $(addprefix $(UTIL_DIR)/, \
	alloc_or_exit.c \
)

SRC_DIR = ./src
SRCS = $(addprefix $(SRC_DIR)/, \
	$(INIT_SRCS) \
	$(ERROR_SRCS) \
	$(UTIL_SRCS) \
	main.c \
)
