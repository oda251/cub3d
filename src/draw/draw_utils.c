
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

// void convert_to_radian(t_data *data)
// {
// 	data->player.radians = vector_to_radians(data->player.direction.x, data->player.direction.y);
// }