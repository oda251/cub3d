/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:43:09 by yoda              #+#    #+#             */
/*   Updated: 2024/04/28 22:59:57 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_error.h"

void	exit_with_message(char *err_location, char *message)
{
	error_message(err_location, message);
	exit(EXIT_FAILURE);
}

// if message is NULL, strerror(errno) is used
void	error_message(char *err_location, char *message)
{
	ft_putstr_fd("Error\n", 2);
	if (err_location)
	{
		ft_putstr_fd(err_location, 2);
		ft_putstr_fd(": ", 2);
	}
	else
		ft_putstr_fd("cub3d: ", 2);
	if (message)
		ft_putstr_fd(message, 2);
	else
		ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
}
