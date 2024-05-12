/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:48:27 by rnogueir          #+#    #+#             */
/*   Updated: 2023/10/19 17:37:54 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;

	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	if (!size || len_d >= size)
		return (len_s + size);
	if (size - len_d > len_s)
		ft_memcpy(dest + len_d, src, len_s + 1);
	else
	{
		ft_memcpy(dest + len_d, src, size - len_d - 1);
		dest[size - 1] = '\0';
	}
	return (len_d + len_s);
}
