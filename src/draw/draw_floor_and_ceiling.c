#include "draw.h"

void	update_pixel_color(t_data *data, int x, int y, uint32_t color)
{
	const	t_mlx	mlx = data->mlx;
	int		pixel;
	
	if (mlx.endian == 1)
	{
		pixel = y * mlx.size_line + x * (mlx.bits_per_pixel / 8);
		*(t_rgbo *)(&mlx.addr[pixel]) = color;
	}
	else
	{
		pixel = y * mlx.size_line + (x + 1) * (mlx.bits_per_pixel / 8);
		mlx.addr[pixel - 1] = color >> 24;
		mlx.addr[pixel - 2] = color >> 16;
		mlx.addr[pixel - 3] = color >> 8;
		mlx.addr[pixel - 4] = color;
	}
}

void	draw_floor_and_ceiling(t_data *data)
{
	int			x;
	int			y;
	t_rgbo		color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < WIN_HEIGHT / 2)
			color = data->color.ceiling;
		else
			color = data->color.floor;
		x = 0;
		while (x < WIN_WIDTH)
		{
			update_pixel_color(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}
