/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:42:44 by misuzuki          #+#    #+#             */
/*   Updated: 2023/09/25 17:57:40 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	return (0);
}
