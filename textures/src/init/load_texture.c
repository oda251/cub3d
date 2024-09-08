/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 05:58:11 by oda251            #+#    #+#             */
/*   Updated: 2024/08/23 05:58:31 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	open_image(t_data *data, t_img *img, char *path)
{
	size_t	i;

	i = ft_strlen(path);
	if (i < 5)
		exit_with_message(NULL, "invalid texture path");
	if (ft_strcmp(path + i - 4, ".xpm") == 0)
	{
		img->img = mlx_xpm_file_to_image(
				data->mlx, path, &img->width, &img->height);
		if (!img->img)
			exit_with_message(
				"mlx_xpm_file_to_image", "failed to load texture");
	}
	else
		exit_with_message(NULL, "invalid texture extension");
}

static void	load_door_texture(t_data *data)
{
	t_texture	*tex;

	tex = &data->tex;
	open_image(data, &tex->img_door, tex->path_door);
	tex->img_door.addr = mlx_get_data_addr(
			tex->img_door.img, &tex->img_door.bits_per_pixel,
			&tex->img_door.size_line, &tex->img_door.endian);
}

void	load_texture(t_data *data)
{
	t_texture	*tex;
	t_direction	dir;

	tex = &data->tex;
	dir = 0;
	while (dir < 4)
	{
		open_image(data, &tex->img[dir], tex->path[dir]);
		tex->img[dir].addr = mlx_get_data_addr(
				tex->img[dir].img, &tex->img[dir].bits_per_pixel,
				&tex->img[dir].size_line, &tex->img[dir].endian);
		dir++;
	}
	load_door_texture(data);
}
