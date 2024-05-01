/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:43:29 by yoda              #+#    #+#             */
/*   Updated: 2024/04/28 22:55:38 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ERROR_H
# define CUB_ERROR_H
# include <errno.h>
# include <string.h>
# include "libft.h"
# include "type.h"

//error.c//
void	exit_with_message(char *err_location, char *message);
void	error_message(char *err_location, char *message);

//free.c//
void    free_images(t_data *data);

#endif
