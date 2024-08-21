/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:57:45 by yoda              #+#    #+#             */
/*   Updated: 2024/08/22 05:54:06 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H
# include "libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <time.h>
# define TITLE "cub3D"
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define MINIMAP_SIZE 10
# define MINIMAP_TILE_SIZE 16
# define MOUSE_SENSITIVITY 0.1
# define MOVE_RATE 0.1
# define ROTATE_RATE 1
# define FPS 15
# define PI 3.14159265
# define MAX_DOOR_STATUS 6

typedef long long		t_ms;
typedef struct timeval	t_time;

typedef enum e_object_type
{
	NONE,
	EMPTY,
	WALL,
	DOOR,
	PLAYER,
}					t_object_type;

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_vector_int
{
	int				x;
	int				y;
}					t_vector_int;

typedef struct s_texture
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
}					t_texture;

typedef uint32_t t_rgbo;

typedef struct s_bg_color
{
	t_rgbo			floor;
	t_rgbo			ceiling;
}					t_bg_color;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_player
{
	t_vector		position;
	int				angle;               //上下のことか？ //左右方向を度数法で表現したもの
	double radians;          //ラジアン
	double left_ray;         //どこまで見れるか
	double right_ray;        //どこまで見れるか
	t_vector direction;      //直交座標系 //左右方向を単位ベクトルで表現したもの
	t_vector left_direction; // 視野の左端の方向（ベクトル）
	t_vector		right_direction;
}					t_player;

typedef struct s_key_input
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}					t_key_input;

typedef struct s_cub_time
{
	long long		ticks;
	t_ms			tick_start;
}					t_cub_time;

typedef struct s_door
{
	t_vector_int	pos;
}					t_door;

typedef struct s_data
{
	void					*mlx;
	void					*win;
	t_img					img_view;
	t_img					img_minimap;
	t_cub_time				time;
	t_key_input				key_input;
	t_texture				tex;
	t_bg_color				bg_color;
	t_player				player;
	t_vector_int			mouse;
	t_list					*doors;
	t_vector_int			mouse_prev;
	char					**map;
	char					**door_map;
	int						map_width;
	int						map_height;
}					t_data;

#endif
