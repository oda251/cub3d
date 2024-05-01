#ifndef DRAW_H
# define DRAW_H
# include <math.h>
# include "libft.h"
# include "type.h"

//draw_floor_and_ceiling.c//
void	draw_floor_and_ceiling(t_data *data);

//redraw.c//
void	draw_wall(t_data *data);

//draw_utils.c//
t_vector radians_to_vector(double radians);
double vector_to_radians(double x, double y);

#endif