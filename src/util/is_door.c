/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 06:11:34 by oda251            #+#    #+#             */
/*   Updated: 2024/08/23 06:11:35 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_util.h"

bool	is_door(t_data *data, t_vector_int pos)
{
	if (data->map[pos.y][pos.x] != DOOR)
		return (false);
	if (data->door_map[pos.y][pos.x] < MAX_DOOR_STATUS)
		return (true);
	return (false);
}
