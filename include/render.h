/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:19:30 by yoda              #+#    #+#             */
/*   Updated: 2024/05/06 17:20:56 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "type.h"

// put_pixel.c
void	put_pixel(t_data *data, t_vector_int cur, t_rgb color);
// render_minimap.c
void	render_minimap(t_data *data);

#endif
