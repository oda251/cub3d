/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:25:54 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 18:20:07 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_util.h"

t_vector	plus_vector(t_vector a, t_vector b)
{
	return ((t_vector){a.x + b.x, a.y + b.y});
}
