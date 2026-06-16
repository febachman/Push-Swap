/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbachman <fbachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:39:36 by fbachman          #+#    #+#             */
/*   Updated: 2026/05/26 16:09:37 by fbachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	int		is_word;
	size_t	word_count;
	size_t	i;

	if (!s)
		return (0);
	is_word = 0;
	word_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			is_word = 0;
		if (s[i] != c)
		{
			if (is_word == 0)
			{
				is_word = 1;
				word_count++;
			}
		}
		i++;
	}
	return (word_count);
}

static void	ft_free_words(char **words, size_t i)
{
	while (i > 0)
	{
		i--;
		free(words[i]);
	}
	free(words);
}

static int	ft_write_words(char **words, char const *s, char c)
{
	unsigned int	start;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (1);
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		words[j] = ft_substr(s, start, (i - start));
		if (!words[j])
		{
			ft_free_words(words, j);
			return (0);
		}
		j++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_words;
	int		status;
	char	**words;

	if (!s)
		return (NULL);
	num_words = ft_count_words(s, c);
	words = malloc((num_words + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	status = ft_write_words(words, s, c);
	if (status == 0)
		return (NULL);
	words[num_words] = NULL;
	return (words);
}
