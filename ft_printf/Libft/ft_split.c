/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:13:03 by habe              #+#    #+#             */
/*   Updated: 2025/05/30 15:44:16 by babe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	free_split(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

static int	fill_words(char **ans, char const *s, char c, size_t word_count)
{
	size_t	start;
	size_t	end;
	size_t	i;

	end = 0;
	i = 0;
	while (i < word_count)
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != '\0' && s[end] != c)
			end++;
		ans[i] = ft_substr(s, start, end - start);
		if (ans[i] == NULL)
		{
			free_split(ans, i - 1);
			return (1);
		}
		i++;
	}
	ans[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	size_t  word_count;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	ans = malloc(sizeof(char *) * (word_count + 1));
	if (ans == NULL)
		return (NULL);
	if (fill_words(ans, s, c, word_count) != 0)
		return (NULL);
	return (ans);
}
