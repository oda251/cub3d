/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:23:18 by yoda              #+#    #+#             */
/*   Updated: 2024/07/14 23:11:15 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_util.h"

t_ms	convert_time(t_time time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	get_current_ms(t_ms *current_ms)
{
	t_time		tmp;

	if (gettimeofday(&tmp, NULL) == -1)
		exit_with_message("gettimeofday", NULL);
	*current_ms = convert_time(tmp);
}
