/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:58:46 by yoda              #+#    #+#             */
/*   Updated: 2024/04/29 00:40:33 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include <stdbool.h>
# include "libft.h"
# include "cub_error.h"

void	*malloc_or_exit(size_t size);
void	*calloc_or_exit(size_t count, size_t size);
char	*strdup_or_exit(char *str);

#endif
