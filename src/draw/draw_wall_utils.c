#include "draw.h"

static uint32_t	get_wall_pixel_color(t_wall_info *wall, int x, int y)
{
	uint32_t	*pix_clr_ptr;

	pix_clr_ptr = (uint32_t *)(wall->addr + y * wall->size_line + x
			* (wall->bits_per_pixel / 8));
	return (*pix_clr_ptr);
}

unsigned int	calculate_wall_pixel(t_wall_info *wall, double pos, int height,
		int count)
{
	unsigned int	color;
	int				w_x;
	int				w_y;

	if (height == 0)
		w_y = 0;
	else if (height > 480)                                                               
		//ここは調整する必要あり
		w_y = ((height - wall->img_height) / 2 + count) * wall->img_height
			/ height; //?
	else
		w_y = count * wall->img_height / height;
	if (w_y >= wall->img_height - 4)
		w_y = wall->img_height - 4;
	w_x = pos * wall->img_width;
	if (w_x >= wall->img_width - 4)
		w_x = wall->img_width - 4;
	color = (unsigned int)get_wall_pixel_color(wall, w_x, w_y);
	return (color);
}

int	get_wall_texture_color(t_data *data, int x, int y) //名前変える
{
	int color;

	color = 0x00FF00; //いる？
	if (data->wall->collisions_dir[x] == SOUTH)
	{
		color = calculate_wall_pixel(data->wall->so, data->wall->wall_pos[x],
				data->wall->wall_height[x], y++);
	}
	else if (data->wall->collisions_dir[x] == NORTH)
	{
		color = calculate_wall_pixel(data->wall->no, data->wall->wall_pos[x],
				data->wall->wall_height[x], y++);
	}
	else if (data->wall->collisions_dir[x] == WEST)
	{
		color = calculate_wall_pixel(data->wall->we, data->wall->wall_pos[x],
				data->wall->wall_height[x], y++);
	}
	else if (data->wall->collisions_dir[x] == EAST)
	{
		color = calculate_wall_pixel(data->wall->ea, data->wall->wall_pos[x],
				data->wall->wall_height[x], y++);
	}
	return (color);
}