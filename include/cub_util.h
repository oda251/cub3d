/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:58:46 by yoda              #+#    #+#             */
/*   Updated: 2024/08/22 05:42:59 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include <sys/time.h>
# include "libft.h"
# include "type.h"
# include "cub_error.h"

// alloc_or_exit.c
void		*malloc_or_exit(size_t size);
void		*calloc_or_exit(size_t count, size_t size);
char		*strdup_or_exit(char *str);
// calc_angle.c
void		angle_to_vector(double angle, t_vector *vec);
double		plus_angle(double angle, double delta);
double		minus_angle(double angle, double delta);
// calc_vector_int.c
t_vector_int	vector_to_int(t_vector v);
// calc_vector.c
t_vector	plus_vector(t_vector a, t_vector b);
// is_door.c
bool		is_door(t_data *data, t_vector_int pos);
// exit_game.c
int			exit_game(int status);
// time_handlers.c
t_ms		convert_time(t_time time);
void		get_current_ms(t_ms *current_ms);

#endif
