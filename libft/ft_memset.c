/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:34:01 by rnogueir          #+#    #+#             */
/*   Updated: 2023/11/08 13:55:07 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*m;
	size_t			idx;

	m = (unsigned char *)s;
	idx = -1;
	while (++idx < n)
		m[idx] = (unsigned char) c;
	return (s);
}
