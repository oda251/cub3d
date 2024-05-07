
#include "draw.h"

double vector_to_radians(double x, double y)
{
    return atan2(y, x);
}

t_vector radians_to_vector(double radians)
{
    t_vector v;

    v.x = cos(radians);
    v.y = sin(radians);
    return (v);
}

double normalize_angle(double angle)
{
    while (angle < 0)
        angle += 2 * M_PI;
    while (angle > 2 * M_PI)
        angle -= 2 * M_PI;
    return (angle);
}

void get_collisions_direction(t_data *data, double radians)
{
	data->ray.direction.x = 0;
	data->ray.direction.y = 0;
	if (radians > 0 && radians < M_PI)
	{
		data->ray.direction.y = -1;
		data->ray.collisions_dir = NORTH;
	}
	else if (radians > M_PI && radians < 2 * M_PI)
	{
		data->ray.direction.y = 1;
		data->ray.collisions_dir = SOUTH;
	}
	if (radians > M_PI_2 && radians < 3 * M_PI_2)
	{
		data->ray.direction.x = -1;
		data->ray.collisions_dir = WEST;
	}
	else if (radians < M_PI_2 || radians > 3 * M_PI_2)
	{
		data->ray.direction.x = 1;
		data->ray.collisions_dir = EAST;
	}
}

bool out_of_map(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->map_height || y < 0 || y >= data->map_width)
		return (true);
	return (false);
}

bool is_wall(char **map, int x, int y)
{
	if (map[x][y] == 'WALL' || map[x][y] == 'EMPTY')
		return (true);
	return (false);
}

// void convert_to_radian(t_data *data)
// {
// 	data->player.radians = vector_to_radians(data->player.direction.x, data->player.direction.y);
// }