/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:37:18 by yoda              #+#    #+#             */
/*   Updated: 2024/04/29 03:54:31 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = input_data(argc, argv);
	(void)data;
	exit(EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
