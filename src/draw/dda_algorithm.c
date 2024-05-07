#include "draw.h"

static t_vector calculate_side_dist(t_vector ray_dir, t_vector map_check, t_vector delta_dist, t_player *player)
{
    t_vector side_dist;

    if (ray_dir.x < 0)
        side_dist.x = (player->position.x - map_check.x) * delta_dist.x;
    else
        side_dist.x = (map_check.x + 1.0 - player->position.x) * delta_dist.x;
    if (ray_dir.y < 0)
        side_dist.y = (player->position.y - map_check.y) * delta_dist.y;
    else
        side_dist.y = (map_check.y + 1.0 - player->position.y) * delta_dist.y;
    return (side_dist);
}

static void update_side_dist_and_map_check(t_dda_data *data)
{
    if (data->side_dist.x < data->side_dist.y)
	{
        data->side_dist.x += data->delta_dist.x;
        data->map_check.x += data->step.x;
        data->ray.collisions_dir = (data->step.x > 0) ? EAST : WEST;
    }
	else
	{
        data->side_dist.y += data->delta_dist.y;
        data->map_check.y += data->step.y;
        data->ray.collisions_dir = (data->step.y > 0) ? SOUTH : NORTH;
    }
}

static void perform_dda(t_dda_data *data, double angle)
{
    int hit;

	hit = 0;
    while (!hit)
	{
        update_side_dist_and_map_check(data);
        if (is_wall(data->map, (int)data->map_check.x, (int)data->map_check.y))
		{
            hit = 1;
            if (data->ray.collisions_dir == EAST || data->ray.collisions_dir == WEST)
            {
                data->ray.ray_length = (data->map_check.x - data->player->position.x + (1 - data->step.x) / 2) / data->ray.direction.x;
                data->ray.wall_pos =fmod(data->player->position.x + data->ray.ray_length * cos(angle), 1.0);
            }
            else
            {
                data->ray.ray_length = (data->map_check.y - data->player->position.y + (1 - data->step.y) / 2) / data->ray.direction.y;
                data->ray.wall_pos = fmod(data->player->position.y + data->ray.ray_length * sin(angle), 1.0);
            }
        }
    }
}

t_ray cast_ray(t_player *player, char **map, double angle)
{
    t_ray ray;
    t_vector ray_dir;
    t_dda_data data;

    ray_dir = calculate_ray_direction(angle);
    data.map_check = calculate_map_check(player);
    data.delta_dist = calculate_delta_dist(ray_dir);
    data.step = calculate_step(ray_dir);
    data.side_dist = calculate_side_dist(ray_dir, data.map_check, data.delta_dist, player);
    data.ray = ray;
    data.player = player;
    data.map = map;
    perform_dda(&data, angle);
    return (data.ray);
}