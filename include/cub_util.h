/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:58:46 by yoda              #+#    #+#             */
/*   Updated: 2024/08/20 02:56:27 by oda251           ###   ########.fr       */
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
void		angle_to_vector(int angle, t_vector *vec);
int			plus_angle(int angle, int delta);
int			minus_angle(int angle, int delta);
// calc_vector.c
t_vector	plus_vector(t_vector a, t_vector b);
// exit_game.c
int			exit_game(int status);
// time_handlers.c
t_ms	convert_time(t_time time);
void	get_current_ms(t_ms *current_ms);

#endif
