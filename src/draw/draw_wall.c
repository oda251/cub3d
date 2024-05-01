
#include "draw.h"

void    updata_radian(t_data *data)
{
    data->player.left_ray = data->player.radians + M_PI_4;
    data->player.right_ray = data->player.radians - M_PI_4;
    while (data->player.right_ray < 0)
        data->player.right_ray += 2 * M_PI;
    while (data->player.right_ray > 2 * M_PI)
        data->player.right_ray -= 2 * M_PI;
    while (data->player.left_ray < 0)
        data->player.left_ray += 2 * M_PI;
    while (data->player.left_ray > 2 * M_PI)
        data->player.left_ray -= 2 * M_PI;
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

void	draw_wall(t_data *data)
{
    updata_radian(data);
    updata_vector(data);
}