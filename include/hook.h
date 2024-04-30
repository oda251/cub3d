/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:21:43 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 21:42:19 by yoda             ###   ########.fr       */
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

int		key_hook_pressed(int keycode, t_data *data);
int		key_hook_released(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
void	switch_door(t_data *data);

#endif