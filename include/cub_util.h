/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:58:46 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 19:29:03 by yoda             ###   ########.fr       */
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
void	*malloc_or_exit(size_t size);
void	*calloc_or_exit(size_t count, size_t size);
char	*strdup_or_exit(char *str);
// calc_angle.c
void	angle_to_vector(int angle, t_vector *vec);
int		plus_angle(int angle, int delta);
// exit_game.c
int		exit_game(int status);

#endif
