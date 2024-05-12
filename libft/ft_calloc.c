/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:11:43 by rnogueir          #+#    #+#             */
/*   Updated: 2023/10/13 16:44:21 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;	
	size_t	len;

	len = nmemb * size;
	mem = malloc(len);
	if (!mem)
		return (NULL);
	ft_bzero(mem, len);
	return ((void *)mem);
}
