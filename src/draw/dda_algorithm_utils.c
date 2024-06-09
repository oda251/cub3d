#include "draw.h"

t_vector	calculate_ray_direction(double angle)
{
	t_vector	ray_dir;

	ray_dir.x = cos(angle);
	ray_dir.y = sin(angle);
	return (ray_dir);
}

t_vector	calculate_map_check(t_player *player)
{
	t_vector	map_check;

	map_check.x = floor(player->position.x);
	map_check.y = floor(player->position.y);
	return (map_check);
}

t_vector	calculate_delta_dist(t_vector ray_dir)
{
	t_vector	delta_dist;

	delta_dist.x = fabs(1 / ray_dir.x);
	delta_dist.y = fabs(1 / ray_dir.y);
	return (delta_dist);
}

t_vector	calculate_step(t_vector ray_dir)
{
	t_vector	step;

	if (ray_dir.x < 0)
		step.x = -1;
	else
		step.x = 1;
	if (ray_dir.y < 0)
		step.y = -1;
	else
		step.y = 1;
	return (step);
}
