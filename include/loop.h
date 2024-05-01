/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:42:22 by yoda              #+#    #+#             */
/*   Updated: 2024/05/01 15:09:07 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H
# include "type.h"
# include "hook.h"

void	reflect_key(t_data *data);
void	img_loop(t_data *data);
void	move_player(t_data *data, t_direction direction);
void	rotate_angle(t_data *data, t_direction direction);

#endif
