/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refletc_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:23:15 by yoda              #+#    #+#             */
/*   Updated: 2024/05/01 15:08:50 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	reflect_key(t_data *data)
{
	if (data->key.w)
		move_player(data, FORWARD);
	if (data->key.s)
		move_player(data, BACKWARD);
	if (data->key.a)
		move_player(data, LEFT);
	if (data->key.d)
		move_player(data, RIGHT);
	if (data->key.l)
		rotate_angle(data, LEFT);
	if (data->key.r)
		rotate_angle(data, RIGHT);
}
