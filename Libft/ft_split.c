/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misuzuki <misuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:12:56 by misuzuki          #+#    #+#             */
/*   Updated: 2023/10/05 17:55:56 by misuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_null(char **letter, size_t i)
{
	if (i == 0)
	{
		free(letter);
		return (NULL);
	}
	i--;
	while (i > 0)
	{
		free(letter[i]);
		i--;
	}
	free(letter[0]);
	free(letter);
	return (NULL);
}

static int	ft_strlen_split(char *src, char c)
{
	size_t	len;

	len = 0;
	while (*src && *src != c)
	{
		len++;
		src++;
	}
	return (len);
}

static char	*ft_strdup_sub(char *src, int length)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = (char *)malloc(length + 1);
	if (copy == NULL)
		return (NULL);
	while (*src && length > 0)
	{
		copy[i] = *src;
		src++;
		i++;
		length--;
	}
	copy[i] = '\0';
	return (copy);
}

static size_t	word_count(char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

char	**ft_split(char *str, char c)
{
	char	**letter;
	size_t	count;
	size_t	i;
	size_t	length;

	if (str == NULL)
		return (NULL);
	count = word_count(str, c);
	letter = (char **)malloc(sizeof(char *) * (count + 1));
	if (letter == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*str && *str == c)
			str++;
		length = ft_strlen_split(str, c);
		letter[i] = ft_strdup_sub(str, length);
		if (letter[i] == NULL)
			return (ft_split_null(letter, i));
		str = str + length;
		i++;
	}
	letter[i] = NULL;
	return (letter);
}
