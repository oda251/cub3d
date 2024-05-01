#include "draw.h"

static void update_pixel_color(t_data *data, int x, int y, uint32_t color)
{
    char *pos;

    pos = data->mlx.addr + y * data->mlx.size_line + x * (data->mlx.bits_per_pixel / 8);
    *(uint32_t *) pos = color;
}

void	draw_floor_and_ceiling(t_data *data)
{
	int	x;
	int	y;
    uint32_t color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < WIN_HEIGHT / 2)
			color = data->color.ceiling->encode;
		else
			color = data->color.floor->encode;
        x = 0;
		while (x < WIN_WIDTH)
		{
			updata_pixel_color(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}

