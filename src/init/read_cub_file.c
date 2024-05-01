/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:28:29 by yoda              #+#    #+#             */
/*   Updated: 2024/04/29 03:23:54 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_identifier	identify_params(char *line);
void			input_map(char *line, t_list **list);
void			input_params(char *line, t_data *data, t_identifier identifier);

void	read_cub_file(int fd, t_data *data, t_list **map_list)
{
	bool			map_started;
	char			*line;
	t_identifier	identifier;

	map_started = false;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = omit_line_break(line);
		identifier = identify_params(line);
		if (map_started || identifier == MAP)
		{
			map_started = true;
			input_map(line, map_list);
		}
		else if (identifier != BR)
			input_params(line, data, identifier);
		free(line);
	}
}

t_identifier	identify_params(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (NO);
	if (ft_strncmp(line, "SO", 2) == 0)
		return (SO);
	if (ft_strncmp(line, "WE", 2) == 0)
		return (WE);
	if (ft_strncmp(line, "EA", 2) == 0)
		return (EA);
	if (ft_strncmp(line, "C", 1) == 0)
		return (C);
	if (ft_strncmp(line, "F", 1) == 0)
		return (F);
	if (*line == '\0')
		return (BR);
	return (MAP);
}

void	input_map(char *line, t_list **list)
{
	t_list	*new;

	new = ft_lstnew(strdup_or_exit(line));
	if (!new)
		exit_with_message("malloc", strerror(errno));
	ft_lstadd_back(list, new);
}

void	input_params(char *line, t_data *data, t_identifier identifier)
{
	if (identifier == NO)
		data->tex.no = parse_tex_path(line);
	else if (identifier == SO)
		data->tex.so = parse_tex_path(line);
	else if (identifier == WE)
		data->tex.we = parse_tex_path(line);
	else if (identifier == EA)
		data->tex.ea = parse_tex_path(line);
	else if (identifier == C)
		data->color.ceiling = parse_color(line);
	else if (identifier == F)
		data->color.floor = parse_color(line);
	encode_rgba(data->color.floor);
	encode_rgba(data->color.ceiling);
}
