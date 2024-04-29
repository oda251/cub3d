/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:43:23 by misuzuki          #+#    #+#             */
/*   Updated: 2023/10/04 15:25:36 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*result;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	result = NULL;
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			while (result != NULL)
			{
				new = result->next;
				del(result->content);
				free(result);
				result = new;
			}
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
