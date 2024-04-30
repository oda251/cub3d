/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vector_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:25:54 by yoda              #+#    #+#             */
/*   Updated: 2024/04/30 17:59:39 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_util.h"

t_vector_int	plus_vector_int(t_vector_int a, t_vector_int b)
{
	return ((t_vector_int){a.x + b.x, a.y + b.y});
}
