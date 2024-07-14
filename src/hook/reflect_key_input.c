/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect_key_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:06:33 by oda251            #+#    #+#             */
/*   Updated: 2024/07/14 23:07:01 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	reflect_key_input(t_data *data)
{
	if (data->key_input.w)
		move_player(data, FORWARD);
	if (data->key_input.a)
		move_player(data, LEFT);
	if (data->key_input.s)
		move_player(data, BACKWARD);
	if (data->key_input.d)
		move_player(data, RIGHT);
	if (data->key_input.space)
		switch_door(data);
	if (data->key_input.left)
		rotate_angle(data, LEFT);
	if (data->key_input.right)
		rotate_angle(data, RIGHT);
}
