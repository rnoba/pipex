/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:11:18 by rnogueir          #+#    #+#             */
/*   Updated: 2023/11/14 11:27:41 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_prepare_next_call(char *buffer, char *new_line)
{
	size_t	new_line_len;

	new_line_len = ft_strlen_del(new_line, '\0');
	ft_memcpy(buffer, new_line, new_line_len);
	ft_memset(buffer + new_line_len, '\0', BUFFER_SIZE - new_line_len + 1);
}

static void	*ft_free_and_return_null(char *heap)
{
	free(heap);
	return (NULL);
}

static char	*ft_get_line(int fd, char *buffer)
{
	char	*line;
	char	*new_line;
	ssize_t	b_read;

	line = NULL;
	new_line = NULL;
	b_read = 1;
	while (!new_line)
	{
		if (!*buffer)
			b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (ft_free_and_return_null(line));
		if (b_read == 0)
			return (line);
		line = ft_strjoin_del(line, buffer, '\n');
		if (!line)
			return (NULL);
		new_line = ft_strchr(buffer, '\n');
		if (!new_line)
			ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	}
	ft_prepare_next_call(buffer, new_line + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	return (ft_get_line(fd, buffer));
}
