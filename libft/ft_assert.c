/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:27:20 by rnogueir          #+#    #+#             */
/*   Updated: 2023/10/11 15:27:39 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_assert(int pred, const char *error_msg)
{
	if (!pred)
	{
		ft_putendl_fd((char *)error_msg, 2);
		exit (1);
	}
}
