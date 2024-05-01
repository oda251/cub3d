/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:37:18 by yoda              #+#    #+#             */
/*   Updated: 2024/05/01 15:06:33 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = input_data(argc, argv);
	init_mlx(data);
	set_hook(data);
	mlx_loop_hook(data->mlx.mlx, cub_loop, data);
	mlx_loop(data->mlx.mlx);
	return (0);
}
