/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:51:40 by rnogueir          #+#    #+#             */
/*   Updated: 2023/11/08 14:03:15 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_n;

	if (*needle == '\0')
		return ((char *)haystack);
	len_n = ft_strlen(needle);
	while (*haystack && len >= len_n && ft_strncmp(haystack, needle, len_n))
	{
		len--;
		haystack++;
	}
	if (len >= len_n && 0 == ft_strncmp(haystack, needle, len_n))
		return ((char *)haystack);
	return (NULL);
}
