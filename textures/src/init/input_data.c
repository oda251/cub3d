/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:05:29 by yoda              #+#    #+#             */
/*   Updated: 2024/09/08 17:42:05 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	check_filename(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < ft_strlen(EXTENSION) || ft_strncmp(filename + len
			- ft_strlen(EXTENSION), EXTENSION, ft_strlen(EXTENSION)))
		exit_with_message(NULL, "Invalid extension");
}

t_data	*input_data(int argc, char **argv)
{
	int		fd;
	t_data	*data;
	t_list	*map_list;

	if (argc != 2)
		exit_with_message(NULL, "Invalid number of arguments");
	check_filename(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_with_message("open", strerror(errno));
	data = (t_data *)calloc_or_exit(sizeof(t_data), 1);
	map_list = NULL;
	read_cub_file(fd, data, &map_list);
	close(fd);
	convert_map(data, map_list);
	ft_lstclear(&map_list, free);
	validate_data(data);
	return (data);
}
