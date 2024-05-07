
#include "draw.h"

void    updata_radian(t_data *data)
{
    data->player.left_ray = data->player.radians + M_PI_4;
    data->player.right_ray = data->player.radians - M_PI_4;
	data->player.left_ray = normalize_angle(data->player.left_ray);
	data->player.right_ray = normalize_angle(data->player.right_ray);
}

void update_vector(t_data *data)
{
    data->player.direction.x = cos(data->player.radians);
    data->player.direction.y = sin(data->player.radians);
    data->player.left_direction.x = cos(data->player.radians + M_PI_4);
    data->player.left_direction.y = sin(data->player.radians + M_PI_4);
    data->player.right_direction.x = cos(data->player.radians - M_PI_4);
    data->player.right_direction.y = sin(data->player.radians - M_PI_4);
}

static void input_ray_data(t_data *data, t_ray ray, int x)
{
	data->wall->ray_length[x] = ray.ray_length;
	data->wall->collisions_dir[x] = ray.collisions_dir;
	data->wall->wall_pos[x]= ray.wall_pos;
}

void	cast_rays_across_screen(t_data	*data)
{
	t_ray	ray;
	int		x;
	double	ray_radian;

	x = 0;
	while (x <= WIN_WIDTH)
	{
		ray_radian = data->player.right_ray + (M_PI_2 * x / WIN_WIDTH);
		ray_radian = normalize_angle(ray_radian);
		ray = cast_ray(&data->player, data->map, ray_radian);
		input_ray_data(data, ray, x);
		x++;
	}
}

void	draw_wall(t_data *data)
{
	int x;

    updata_radian(data);
    updata_vector(data);
	cast_rays_across_screen(data);
	x = 0;
	while (x <= WIN_WIDTH)
	{
		data->wall->wall_height[x] = \
			(int)((WIN_HEIGHT / (data->wall->ray_length[x] * 8 / 7))); //to do 調節すること
		x++;
	}
    //ここに入れる
}

// typedef struct s_count//いらない気がする
// {
// 	int	i;
// 	int	j;
// 	int	k;
// 	int	l;

// 	int	y;
// }	t_count;

// void	count_init(t_count *count)
// {
// 	(*count).i = 0;
// 	(*count).j = 0;
// 	(*count).k = 0;
// 	(*count).l = 0;
// 	(*count).y = 0;
// }

void	draw_wall(t_data *data)
{
	int		x;
	int		y;
	int		color;

	//calculate_visual_height(data);
	x = 0;
	//color = 0x00FF00;//いらないと思う
	while (x < WIN_WIDTH)
	{
		//count_init(&count);
		y = 0;
		while (y < WIN_HEIGHT)
		{
			if ((WIN_HEIGHT - data->wall->wall_height[x]) / 2 <= y \
				&& y <= (WIN_HEIGHT + data->wall->wall_height[x]) / 2)
			{
				color = get_wall_texture_color(data, x, y);
				update_pixel_color(data, x, y, color);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}