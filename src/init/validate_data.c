/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:05:17 by yoda              #+#    #+#             */
/*   Updated: 2024/06/10 01:51:04 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	validate_params(t_data *data);
void	validate_map(t_data *data);

void	validate_data(t_data *data)
{
	validate_params(data);
	validate_map(data);
}

void	validate_params(t_data *data)
{
	if (data->tex.ea == NULL)
		exit_with_message(NULL, "EA texture is not set");
	if (data->tex.no == NULL)
		exit_with_message(NULL, "NO texture is not set");
	if (data->tex.so == NULL)
		exit_with_message(NULL, "SO texture is not set");
	if (data->tex.we == NULL)
		exit_with_message(NULL, "WE texture is not set");
	if (data->color.ceiling == 0)
		exit_with_message(NULL, "Ceiling color is not set");
	if (data->color.floor == 0)
		exit_with_message(NULL, "Floor color is not set");
	if (data->map == NULL)
		exit_with_message(NULL, "Map is not set");
	if (data->player.position.x < 0)
		exit_with_message(NULL, "Player is not set");
}

void	validate_map(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			if ((data->map[i][j] == EMPTY
				|| data->map[i][j] == DOOR_CLOSED
				|| data->map[i][j] == DOOR_OPEN)
				&& (data->map[i-1][j] == NONE
				|| data->map[i+1][j] == NONE
				|| data->map[i][j-1] == NONE
				|| data->map[i][j+1] == NONE))
				exit_with_message(NULL, "Map is not surrounded by walls");
		}
	}
}
