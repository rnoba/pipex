/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:45:33 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/17 16:45:35 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_realloc(void *heap, size_t prev_size, size_t new_size)
{
	char	*new_block;

	if (new_size == 0)
	{
		free(heap);
		return (NULL);
	}
	if (!heap)
		return (malloc(new_size));
	ft_assert(prev_size <= new_size, "Error(ft_realloc): invalid size");
	new_block = malloc(new_size);
	if (new_block)
	{
		ft_bzero(new_block, new_size);
		ft_memcpy(new_block, heap, prev_size);
		free(heap);
	}
	return (new_block);
}
