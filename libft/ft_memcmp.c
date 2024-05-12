/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:48:21 by rnogueir          #+#    #+#             */
/*   Updated: 2023/10/13 15:18:56 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			idx;
	unsigned char	*sp;
	unsigned char	*sp1;

	sp = (unsigned char *)s1;
	sp1 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	idx = -1;
	while (++idx < n)
		if ((unsigned char)sp[idx] != (unsigned char)sp1[idx])
			return (((unsigned char)sp[idx] - (unsigned char)sp1[idx]));
	return (0);
}
