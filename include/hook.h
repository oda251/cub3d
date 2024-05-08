/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:21:43 by yoda              #+#    #+#             */
/*   Updated: 2024/05/06 18:32:37 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H
# include <stdio.h>
# include "type.h"
# include "mlx.h"
# include "key_macro.h"
# include "cub_util.h"
# include "cub_error.h"

typedef enum e_direction
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
}	t_direction;

// main
void	set_hook(t_data *data);
// else
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int x, int y, t_data *data);
void	move_player(t_data *data, t_direction direction);
void	rotate_angle(t_data *data, t_direction direction);
void	switch_door(t_data *data);

#endif
