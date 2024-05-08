/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:57:45 by yoda              #+#    #+#             */
/*   Updated: 2024/05/06 18:32:23 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H
# include <stdbool.h>
# include "libft.h"
# define TITLE "cub3D"
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define MINIMAP_SIZE 10
# define MINIMAP_TILE_SIZE 16
# define MOUSE_SENSITIVITY 0.1
# define MOVE_RATE 0.1
# define ROTATE_RATE 1
# define PI 3.14159265

typedef enum e_object
{
	DOOR_OPEN,
	NONE,
	EMPTY,
	WALL,
	DOOR_CLOSED,
	PLAYER,
}	t_object;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_vector_int
{
	int	x;
	int	y;
}	t_vector_int;

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
	int			angle;
	t_vector	direction;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_mlx;

typedef struct s_key
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	l;
	bool	r;
}	t_key;

typedef struct s_data
{
	t_key			key;
	t_mlx			mlx;
	t_texture		tex;
	t_color			color;
	t_player		player;
	t_vector_int	mouse;
	char			**map;
	int				map_width;
	int				map_height;
}	t_data;

#endif
