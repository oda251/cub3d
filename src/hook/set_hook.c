/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:37:47 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 20:37:14 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	set_hook(t_data *data)
{
	mlx_hook(data->mlx.win, EVENT_CLOSE_BTN, (1L << 2), exit_game, NULL);
	mlx_key_hook(data->mlx.win, key_hook, data);
}
