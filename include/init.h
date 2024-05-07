/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:05:50 by yoda              #+#    #+#             */
/*   Updated: 2024/05/07 21:43:13 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include "cub_error.h"
# include "cub_util.h"
# include "draw.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include "type.h"
# include <fcntl.h>
# include <stdlib.h>
# define MAX_MAP_SIZE 2048

typedef enum e_identifier
{
	SO,
	NO,
	WE,
	EA,
	C,
	F,
	BR,
	MAP,
}			t_identifier;

typedef struct s_input
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*c;
	char	*f;
	t_list	*map;
}			t_input;

void		read_cub_file(int fd, t_data *data, t_list **map_list);
void		convert_map(t_data *data, t_list *map_list);
char		*parse_tex_path(char *line);
t_rgb		*parse_color(char *line);
uint32_t	encode_rgba(t_rgb *color);
void		validate_data(t_data *data);

// init_images.c//
void		init_images(t_data *data);

// util
char		*skip_spaces(char *str);
char		*validate_path(char *path);
char		*omit_line_break(char *line);

#endif
