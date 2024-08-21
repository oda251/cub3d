/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:21:43 by yoda              #+#    #+#             */
/*   Updated: 2024/08/22 05:54:00 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H
# include <stdio.h>
# include <X11/X.h>
# include "type.h"
# include "mlx.h"
# include "key_macro.h"
# include "cub_util.h"
# include "cub_error.h"

typedef enum e_move_direction
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
}	t_move_direction;

// main
void	set_hook(t_data *data);
// else
int		key_pressed_hook(int keycode, t_data *data);
int		key_released_hook(int keycode, t_data *data);
int		loop_hook(t_data *data);
int		mouse_hook(int x, int y, t_data *data);
void	move_player(t_data *data, t_move_direction direction);
void	reflect_input(t_data *data);
void	rotate_angle(t_data *data, t_move_direction direction);
void	handle_door(t_data *data);

#endif
