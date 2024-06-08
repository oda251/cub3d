#include "init.h"

// static void	init(t_data *data)
// {
// 	data->wall = calloc_or_exit(1, sizeof(t_wall));
// 	data->wall->no = calloc_or_exit(1, sizeof(t_wall_info));
// 	data->wall->so = calloc_or_exit(1, sizeof(t_wall_info));
// 	data->wall->we = calloc_or_exit(1, sizeof(t_wall_info));
// 	data->wall->ea = calloc_or_exit(1, sizeof(t_wall_info));
// 	data->wall->collisions_dir = calloc_or_exit(WIN_WIDTH,
// 			sizeof(t_direction_draw));
// 	data->wall->ray_length = calloc_or_exit(WIN_WIDTH, sizeof(double));
// 	data->wall->wall_pos = calloc_or_exit(WIN_WIDTH, sizeof(double));
// 	data->wall->wall_height = calloc_or_exit(WIN_WIDTH, sizeof(int));
// }

static void	get_wall_addr(t_wall *wall)
{
	wall->no->addr = mlx_get_data_addr(wall->no->wall_image,
			&wall->no->bits_per_pixel, &wall->no->size_line, &wall->no->endian);
	if (!wall->no->addr)
		exit_with_message("mlx_get_data_addr",
			"failed to get north image address");
	wall->so->addr = mlx_get_data_addr(wall->so->wall_image,
			&wall->so->bits_per_pixel, &wall->so->size_line, &wall->so->endian);
	if (!wall->so->addr)
		exit_with_message("mlx_get_data_addr",
			"failed to get south image address");
	wall->we->addr = mlx_get_data_addr(wall->we->wall_image,
			&wall->we->bits_per_pixel, &wall->we->size_line, &wall->we->endian);
	if (!wall->we->addr)
		exit_with_message("mlx_get_data_addr",
			"failed to get west image address");
	wall->ea->addr = mlx_get_data_addr(wall->ea->wall_image,
			&wall->ea->bits_per_pixel, &wall->ea->size_line, &wall->ea->endian);
	if (!wall->ea->addr)
		exit_with_message("mlx_get_data_addr",
			"failed to get east image address");
}

void	init_images(t_data *data)
{
	data->wall->no->wall_image = mlx_xpm_file_to_image(data->mlx.mlx,
			data->tex.no, &data->wall->no->img_width,
			&data->wall->no->img_height);
	if (!data->wall->no->wall_image)
		exit_with_message("mlx_xpm_file_to_image",
			"failed to convert north xpm file to image");
	data->wall->so->wall_image = mlx_xpm_file_to_image(data->mlx.mlx,
			data->tex.so, &data->wall->so->img_width,
			&data->wall->so->img_height);
	if (!data->wall->so->wall_image)
		exit_with_message("mlx_xpm_file_to_image",
			"failed to convert south xpm file to image");
	data->wall->we->wall_image = mlx_xpm_file_to_image(data->mlx.mlx,
			data->tex.we, &data->wall->we->img_width,
			&data->wall->we->img_height);
	if (!data->wall->we->wall_image)
		exit_with_message("mlx_xpm_file_to_image",
			"failed to convert west xpm file to image");
	data->wall->ea->wall_image = mlx_xpm_file_to_image(data->mlx.mlx,
			data->tex.ea, &data->wall->ea->img_width,
			&data->wall->ea->img_height);
	if (!data->wall->ea->wall_image)
		exit_with_message("mlx_xpm_file_to_image",
			"failed to convert East xpm file to image");
	get_wall_addr(data->wall);
}