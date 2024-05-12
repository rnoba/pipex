/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:43:18 by rnogueir          #+#    #+#             */
/*   Updated: 2023/10/16 14:43:19 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*s_p;

	idx = -1;
	s_p = (unsigned char *)s;
	while (++idx < n)
	{
		if (s_p[idx] == (unsigned char) c)
			return ((void *)&s_p[idx]);
	}
	return (NULL);
}
