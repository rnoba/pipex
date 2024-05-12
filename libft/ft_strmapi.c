/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:18:56 by rnogueir          #+#    #+#             */
/*   Updated: 2023/10/16 14:40:57 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	idx;
	size_t	len;
	char	*o;

	len = ft_strlen(s);
	if (!s)
		return (NULL);
	o = malloc(sizeof(char) * (1 + len));
	if (!o)
		return (NULL);
	idx = -1;
	while (++idx < len)
		o[idx] = f(idx, s[idx]);
	o[idx] = '\0';
	return (o);
}
