/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 06:01:40 by oda251            #+#    #+#             */
/*   Updated: 2024/08/23 06:07:44 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_background(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (i < WIN_HEIGHT / 2)
				put_pixel(&data->img_view, (t_vector_int){j, i},
					data->bg_color.ceiling);
			else
				put_pixel(&data->img_view, (t_vector_int){j, i},
					data->bg_color.floor);
			j++;
		}
		i++;
	}
}
