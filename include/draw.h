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
double normalize_angle(double angle);
void get_collisions_direction(t_data *data, double radians);
bool out_of_map(t_data *data, int x, int y);
bool is_wall(char **map, int x, int y);

//dda_algorithm_utils.c//
t_vector calculate_ray_direction(double angle);
t_vector calculate_map_check(t_player *player);
t_vector calculate_delta_dist(t_vector ray_dir);
t_vector calculate_step(t_vector ray_dir);

//dda_algorithm.c//
t_ray cast_ray(t_player *player, char **map, double angle);

#endif