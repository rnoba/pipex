/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:14:32 by rnogueir          #+#    #+#             */
/*   Updated: 2024/04/24 17:01:03 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_del(char *str, char del)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != del)
		len++;
	if (del == '\n' && str[len] == '\n')
		len++;
	return (len);
}

char	*ft_strjoin_del(char *s1, char *s2, char del)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ret;

	s1_len = ft_strlen_del(s1, '\0');
	s2_len = ft_strlen_del(s2, del);
	ret = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1, s1_len);
	ft_memcpy(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = '\0';
	free(s1);
	return (ret);
}
