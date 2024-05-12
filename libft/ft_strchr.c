/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:04:40 by rnogueir          #+#    #+#             */
/*   Updated: 2023/11/08 13:55:31 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;

	idx = -1;
	while (s[++idx])
		if (s[idx] == (unsigned char) c)
			return ((char *)&(s[idx]));
	if (s[idx] == (unsigned char) c)
		return ((char *)&(s[idx]));
	if (!c)
		return ((char *)s);
	return (NULL);
}
