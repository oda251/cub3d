/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:05:50 by yoda              #+#    #+#             */
/*   Updated: 2024/06/10 01:53:57 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"
# include "type.h"
# include "libft.h"
# include "get_next_line.h"
# include "cub_util.h"
# include "cub_error.h"
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
}	t_identifier;

typedef struct s_input
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*c;
	char	*f;
	t_list	*map;
}	t_input;

// main
t_data	*input_data(int argc, char **argv);
void	init_mlx(t_data *data);
void	init_images(t_data *data);
// else
void	read_cub_file(int fd, t_data *data, t_list **map_list);
void	convert_map(t_data *data, t_list *map_list);
char	*parse_tex_path(char *line);
t_rgbo	parse_color(char *line);
void	validate_data(t_data *data);
// util
char	*skip_spaces(char *str);
char	*validate_path(char *path);
char	*omit_line_break(char *line);

#endif
