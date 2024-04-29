/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:57:45 by yoda              #+#    #+#             */
/*   Updated: 2024/04/29 03:31:26 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H
# include <stdbool.h>
# include "libft.h"

typedef enum e_object
{
	DOOR_OPEN,
	NONE,
	EMPTY,
	WALL,
	DOOR_CLOSED,
}	t_object;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_texture;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_color
{
	t_rgb	*floor;
	t_rgb	*ceiling;
}	t_color;

typedef struct s_player
{
	t_vector	position;
	t_vector	direction;
}	t_player;

typedef struct s_data
{
	t_texture	tex;
	t_color		color;
	t_player	player;
	char		**map;
	int			map_width;
	int			map_height;
}	t_data;

#endif
