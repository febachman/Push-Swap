/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:39:53 by fbachman          #+#    #+#             */
/*   Updated: 2026/05/28 11:59:41 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_findbegin(char const *s1, char const *set)
{
	size_t	begin;

	if (!s1 || !set)
		return (0);
	begin = 0;
	while (s1[begin] != '\0' && ft_strchr(set, s1[begin]) != NULL)
		begin++;
	return (begin);
}

static size_t	ft_findend(char const *s1, char const *set, size_t begin)
{
	size_t	end;

	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1);
	if (end == 0)
		return (0);
	end--;
	while (end >= begin && ft_strchr(set, s1[end]) != NULL)
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	begin;
	size_t	end;
	size_t	len;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	begin = ft_findbegin(s1, set);
	end = ft_findend(s1, set, begin);
	if (begin > end || *s1 == '\0')
		len = 0;
	else
		len = end - begin + 1;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s1[begin++];
	str[i] = '\0';
	return (str);
}
