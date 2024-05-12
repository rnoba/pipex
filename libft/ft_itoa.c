/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:50:50 by rnogueir          #+#    #+#             */
/*   Updated: 2023/10/18 16:16:18 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_get_tab_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	n_u;
	size_t			len;
	char			*r;

	len = ft_get_tab_len(n);
	n_u = n;
	r = malloc(sizeof(char) * (1 + len));
	if (!r)
		return (NULL);
	if (n < 0)
		n_u = -n;
	ft_bzero(r, len + 1);
	while (len--)
	{
		r[len] = n_u % 10 + '0';
		n_u /= 10;
	}
	if (n < 0)
		r[0] = '-';
	return (r);
}
