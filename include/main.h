/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:17:45 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 19:09:34 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include "mlx.h"
# include "type.h"
# include "cub_error.h"

t_data	*input_data(int argc, char **argv);
void	init_mlx(t_data *data);
void	set_hook(t_data *data);

#endif
