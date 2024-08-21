#include "render.h"

void	proceed_x(t_dda *dda);
void	proceed_y(t_dda *dda);

void	init_dda(t_data *data, t_dda *dda, t_vector *direction)
{
	dda->x_ray.curr = data->player.position;
	dda->y_ray.curr = data->player.position;
	dda->x_ray.distance = 0;
	dda->y_ray.distance = 0;
	dda->direction = *direction;
	proceed_x(dda);
	proceed_y(dda);
}

t_vector	proceed_dda(t_dda *dda)
{
	if (dda->x_ray.distance <= dda->y_ray.distance)
	{
		dda->x_ray.curr = dda->x_ray.next;
		proceed_x(dda);
		return dda->x_ray.curr;
	}
	else
	{
		dda->y_ray.curr = dda->y_ray.next;
		proceed_y(dda);
		return dda->y_ray.curr;
	}
}

void	proceed_x(t_dda *dda)
{
	t_ray	*ray;

	ray = &dda->x_ray;
	if (dda->direction.x >= 0)
	{
		ray->next.x = ceil(ray->curr.x);
		if (ray->next.x == ray->curr.x)
			ray->next.x++;
	}
	else
	{
		ray->next.x = floor(ray->curr.x);
		if (ray->next.x == ray->curr.x)
			ray->next.x--;
	}
	ray->next.y = ray->curr.y + dda->direction.y * (ray->next.x - ray->curr.x) / dda->direction.x;
	ray->distance += fabs(ray->next.x - ray->curr.x) + fabs(ray->next.y - ray->curr.y);
}

void	proceed_y(t_dda *dda)
{
	t_ray	*ray;

	ray = &dda->y_ray;
	if (dda->direction.y >= 0)
	{
		ray->next.y = ceil(ray->curr.y);
		if (ray->next.y == ray->curr.y)
			ray->next.y++;
	}
	else
	{
		ray->next.y = floor(ray->curr.y);
		if (ray->next.y == ray->curr.y)
			ray->next.y--;
	}
	ray->next.x = ray->curr.x + dda->direction.x * (ray->next.y - ray->curr.y) / dda->direction.y;
	ray->distance += fabs(ray->next.x - ray->curr.x) + fabs(ray->next.y - ray->curr.y);
}
