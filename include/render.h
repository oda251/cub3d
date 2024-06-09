/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:19:30 by yoda              #+#    #+#             */
/*   Updated: 2024/06/10 01:24:18 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "type.h"

// put_pixel.c
void	put_pixel(t_data *data, t_vector_int cur, t_rgbo color);
// render_minimap.c
void	render_minimap(t_data *data);

#endif
