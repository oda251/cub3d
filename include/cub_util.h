/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:58:46 by yoda              #+#    #+#             */
/*   Updated: 2024/06/10 01:43:09 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "type.h"
# include "cub_error.h"

// alloc_or_exit.c
void		*malloc_or_exit(size_t size);
void		*calloc_or_exit(size_t count, size_t size);
char		*strdup_or_exit(char *str);
// calc_angle.c
void		angle_to_vector(int angle, t_vector *vec);
int			plus_angle(int angle, int delta);
// calc_vector.c
t_vector	plus_vector(t_vector a, t_vector b);
// exit_game.c
int			exit_game(int status);
// put_pixel.c
void	put_pixel(t_data *data, t_vector_int cur, t_rgbo color);

#endif
