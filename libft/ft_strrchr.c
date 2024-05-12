/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:35:54 by rnogueir          #+#    #+#             */
/*   Updated: 2023/11/08 13:55:35 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;

	idx = 1 + ft_strlen(s);
	while (--idx)
		if (s[idx] == (unsigned char) c)
			return ((char *)&s[idx]);
	if (s[idx] == (unsigned char) c)
		return ((char *)&s[idx]);
	return (NULL);
}
