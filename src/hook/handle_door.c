/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:22:08 by yoda              #+#    #+#             */
/*   Updated: 2024/08/22 05:53:39 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"


static size_t	calc_distance(t_vector *a, t_vector_int *b)
{
	return (sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2)));
}


void	handle_door(t_data *data)
{
	t_list	*lst;
	t_vector_int	pos;	

	lst = data->doors;
	while (lst)
	{
		pos = ((t_door *)lst->content)->pos;
		if (calc_distance(&data->player.position, &pos) <= 2)
		{
			if (data->door_map[pos.y][pos.x] < MAX_DOOR_STATUS)
				data->door_map[pos.y][pos.x]++;
		}
		else
		{
			if (data->door_map[pos.y][pos.x] > 0)
				data->door_map[pos.y][pos.x] = 0;
		}
		lst = lst->next;
	}
}

