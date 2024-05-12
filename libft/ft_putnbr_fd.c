/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:31:06 by rnogueir          #+#    #+#             */
/*   Updated: 2023/10/16 14:29:32 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_n;

	u_n = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		u_n = -n;
	}
	if (u_n > 9)
		ft_putnbr_fd(u_n / 10, fd);
	ft_putchar_fd(u_n % 10 + '0', fd);
}
