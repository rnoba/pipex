/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:37:05 by rnogueir          #+#    #+#             */
/*   Updated: 2023/11/08 13:48:27 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_strlen_del(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static size_t	ft_get_split_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	if (!(*s))
		return (0);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		len++;
	}
	return (len);
}

static void	ft_free_matrix(char **m)
{
	size_t	idx;

	idx = 0;
	while (m[idx])
	{
		free(m[idx]);
		idx++;
	}
	free(m);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	idx;

	split = malloc(sizeof(char *) * (1 + ft_get_split_len(s, c)));
	if (!split)
		return (NULL);
	idx = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!(*s))
			break ;
		split[idx] = ft_substr(s, 0, ft_strlen_del(s, c));
		if (!split[idx])
		{
			ft_free_matrix(split);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		idx++;
	}
	split[idx] = NULL;
	return (split);
}
