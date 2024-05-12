/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:15:26 by rnogueir          #+#    #+#             */
/*   Updated: 2024/04/23 18:15:45 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strfchr(const char *s, int (*f)(int))
{
	size_t	idx;

	idx = -1;
	while (s && s[++idx])
	{
		if (f(s[idx]))
		{
			return ((char *)&(s[idx]));
		}
	}
	return (NULL);
}
