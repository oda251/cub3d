/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:57:45 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 21:13:45 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H
# include <stdbool.h>
# include "libft.h"
# include "mlx.h"
# define TITLE "cub3D"
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
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
	uint32_t		encode;
}	t_rgb;

typedef struct s_color
{
	t_rgb	*floor;
	t_rgb	*ceiling;
}	t_color;

typedef struct s_player
{
	t_vector	position;
	int			angle;//上下のことか？
	double		radians;//ラジアン
	double		left_ray;//どこまで見れるか
	double		right_ray;//どこまで見れるか
	t_vector	direction;//直交座標系
	t_vector    left_direction; // 視野の左端の方向（ベクトル）
    t_vector    right_direction;
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

typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	NODEF
}	t_direction;

typedef struct s_ray
{
	double		ray_length;//はてな
	double		wall;//はてな
	double		radians;//ラジアン
	t_vector	direction;//方向ベクトル
	t_direction	collisions_dir;
}	t_ray;

typedef struct t_wall
{
	t_wall_info	*no;
	t_wall_info	*so;
	t_wall_info	*we;
	t_wall_info	*ea;
}	t_wall;

typedef struct t_wall_info
{
	void	*wall_image;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		img_width;
	int		img_height;
}	t_wall_info;

typedef struct s_data
{
	t_key		key;
	t_mlx		mlx;
	t_texture	tex;
	t_color		color;
	t_player	player;
	t_ray		ray;
	t_wall		*wall;
	char		**map;
	int			map_width;
	int			map_height;
}	t_data;

#endif
