#include "cub_util.h"

bool	is_door(t_data *data, t_vector_int pos)
{
	if (data->map[pos.y][pos.x] != DOOR)
		return (false);
	if (data->door_map[pos.y][pos.x] < MAX_DOOR_STATUS)
		return (true);
	return (false);
}
