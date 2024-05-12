/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:44:03 by rnogueir          #+#    #+#             */
/*   Updated: 2023/10/16 13:40:01 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*r;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	r = malloc(sizeof(char) * (1 + len_s1 + len_s2));
	if (!r)
		return (NULL);
	ft_memcpy(r, s1, len_s1);
	ft_memcpy(r + len_s1, s2, len_s2);
	r[len_s1 + len_s2] = '\0';
	return (r);
}
