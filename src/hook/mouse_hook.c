/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:55:53 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 19:13:06 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	mouse_hook(int button, int x, int y, t_data *data)
{
	(void)button;
	(void)x;
	(void)y;
	(void)data;
	return (1);
}
