/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vector_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oda251 <oda251@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:25:54 by yoda              #+#    #+#             */
/*   Updated: 2024/08/21 02:48:28 by oda251           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_util.h"

t_vector_int	plus_vector_int(t_vector_int a, t_vector_int b)
{
	return ((t_vector_int){a.x + b.x, a.y + b.y});
}

t_vector_int	vector_to_int(t_vector v)
{
	return ((t_vector_int){v.x, v.y});
}